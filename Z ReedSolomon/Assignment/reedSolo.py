import array
import math

################### INIT and stuff ###################

try:  # pragma: no cover
    bytearray
    _bytearray = bytearray
except NameError:  # pragma: no cover

    def _bytearray(obj=0, encoding="latin-1"):  # pragma: no cover
        '''Simple pure-python bytearray replacement if not implemented'''

        if isinstance(obj, str):
            obj = [ord(ch) for ch in obj.encode(encoding)]
        elif isinstance(obj, int):
            obj = [0] * obj
        return array.array("B", obj)


try:  # pragma: no cover
    # compatibility with Python 2.7
    xrange
except NameError:  # pragma: no cover
    # compatibility with Python 3+
    xrange = range


class ReedSolomonError(Exception):
    pass


gf_exp = _bytearray([1] * 512)
gf_log = _bytearray(256)
field_charac = int(2**8 - 1)


def rwh_primes1(n):
    ''' Returns a list of primes < n '''
    n_half = int(n / 2)
    sieve = [True] * n_half
    for i in xrange(3, int(math.pow(n, 0.5)) + 1, 2):
        if sieve[int(i / 2)]:
            sieve[int((i * i) / 2)::i] = [False] * int((n - i * i - 1) /
                                                       (2 * i) + 1)
    return array.array('i', [2] +
                       [2 * i + 1 for i in xrange(1, n_half) if sieve[i]])


# compute all the prime polynomials of GF(2^8) and store them in a list
def find_prime_polys(generator=2, c_exp=8, fast_primes=False, single=False):
    root_charac = 2  # we're in GF(2)
    field_charac = int(root_charac**c_exp - 1)
    field_charac_next = int(root_charac**(c_exp + 1) - 1)

    if fast_primes:
        prim_candidates = rwh_primes1(
            field_charac_next
        )  # generate maybe prime polynomials and check later if they really are irreducible
        prim_candidates = array.array(
            'i', [x for x in prim_candidates if x > field_charac
                  ])  # filter out too small primes
    else:
        prim_candidates = array.array(
            'i', xrange(field_charac + 2, field_charac_next, root_charac)
        )  # try each possible prime polynomial, but skip even numbers (because divisible by 2 so necessarily not irreducible)

    correct_primes = array.array('i', [])
    for prim in prim_candidates:  # try potential candidates primitive irreducible polys
        seen = _bytearray(
            field_charac + 1
        )  # memory variable to indicate if a value was already generated in the field (value at index x is set to 1) or not (set to 0 by default)
        conflict = False  # flag to know if there was at least one conflict

        x = 1
        for i in xrange(field_charac):

            x = gf_mult_noLUT(x, generator, prim, field_charac + 1)

            if x > field_charac or seen[x] == 1:
                conflict = True
                break

            else:
                seen[x] = 1

        if not conflict:
            correct_primes.append(prim)
            if single:
                return array.array('i', [prim])

    return correct_primes


def init_tables(prim=0x11d, generator=2, c_exp=8):

    global _bytearray
    if c_exp <= 8:
        _bytearray = bytearray
    else:

        def _bytearray(obj=0, encoding="latin-1"):
            '''Fake bytearray replacement, supporting int values above 255'''

            if isinstance(obj,
                          str):  # obj is a string, convert to list of ints
                obj = obj.encode(encoding)
                if isinstance(obj,
                              str):  # Py2 str: convert to list of ascii ints
                    obj = [ord(chr) for chr in obj]
                elif isinstance(
                        obj, bytes
                ):  # Py3 bytes: characters are bytes, need to convert to int for array.array('i', obj)
                    obj = [int(chr) for chr in obj]
                else:
                    raise (ValueError, "Type of object not recognized!")
            elif isinstance(
                    obj, int
            ):  # compatibility with list preallocation bytearray(int)
                obj = [0] * obj
            elif isinstance(obj, bytes):
                obj = [int(b) for b in obj]
            # Else obj is a list of int, it's ok
            return array.array("i", obj)

    # Init global tables
    global gf_exp, gf_log, field_charac
    field_charac = int(2**c_exp - 1)
    gf_exp = _bytearray(
        field_charac * 2
    )  # anti-log (exponential) table. The first two elements will always be [GF256int(1), generator]
    gf_log = _bytearray(field_charac +
                        1)  # log table, log[0] is impossible and thus unused

    x = 1
    for i in xrange(
            field_charac
    ):  # we could skip index 255 which is equal to index 0 because of modulo: g^255==g^0 but either way, this does not change the later outputs (ie, the ecc symbols will be the same either way)
        gf_exp[
            i] = x  # compute anti-log for this value and store it in a table
        gf_log[x] = i  # compute log at the same time
        x = gf_mult_noLUT(x, generator, prim, field_charac + 1)

    for i in xrange(field_charac, field_charac * 2):
        gf_exp[i] = gf_exp[i - field_charac]

    return gf_log, gf_exp, field_charac


def gf_add(x, y):
    '''Add two galois field integers'''
    return x ^ y


def gf_sub(x, y):
    '''Subtract two galois field integers'''
    return x ^ y  # in binary galois field, substraction is just the same as addition (since we mod 2)


def gf_neg(x):
    '''Negate one galois field integer (does nothing)'''
    return x


def gf_inverse(x):
    '''Inverse of a galois field integer'''
    return gf_exp[field_charac - gf_log[x]]  # gf_inverse(x) == gf_div(1, x)


def gf_mul(x, y):
    '''Multiply two galois field integers'''
    if x == 0 or y == 0:
        return 0
    return gf_exp[(gf_log[x] + gf_log[y]) % field_charac]


def gf_div(x, y):
    '''Divide x by y galois field integers'''
    if y == 0:
        raise ZeroDivisionError()
    if x == 0:
        return 0
    return gf_exp[(gf_log[x] + field_charac - gf_log[y]) % field_charac]


def gf_pow(x, power):
    '''Power of x galois field integer'''
    return gf_exp[(gf_log[x] * power) % field_charac]


def gf_mult_noLUT_slow(x, y, prim=0):
    '''Multiplication in Galois Fields on-the-fly without using a precomputed look-up table (and thus it's slower) by using the standard carry-less multiplication + modular reduction using an irreducible prime polynomial.'''

    ### Define bitwise carry-less operations as inner functions ###
    def cl_mult(x, y):
        '''Bitwise carry-less multiplication on integers'''
        z = 0
        i = 0
        while (y >> i) > 0:
            if y & (1 << i):
                z ^= x << i
            i += 1
        return z

    def bit_length(n):
        '''Compute the position of the most significant bit (1) of an integer. Equivalent to int.bit_length()'''
        bits = 0
        while n >> bits:
            bits += 1
        return bits

    def cl_div(dividend, divisor=None):
        '''Bitwise carry-less long division on integers and returns the remainder'''
        # Compute the position of the most significant bit for each integers
        dl1 = bit_length(dividend)
        dl2 = bit_length(divisor)
        # If the dividend is smaller than the divisor, just exit
        if dl1 < dl2:
            return dividend
        # Else, align the most significant 1 of the divisor to the most significant 1 of the dividend (by shifting the divisor)
        for i in xrange(dl1 - dl2, -1, -1):
            # Check that the dividend is divisible (useless for the first iteration but important for the next ones)
            if dividend & (1 << i + dl2 - 1):
                # If divisible, then shift the divisor to align the most significant bits and XOR (carry-less substraction)
                dividend ^= divisor << i
        return dividend

    result = cl_mult(x, y)

    if prim > 0:
        result = cl_div(result, prim)

    return result


def gf_mult_noLUT(x, y, prim=0, field_charac_full=256, carryless=True):

    r = 0
    while y:  # while y is above 0
        if y & 1:
            r = r ^ x if carryless else r + x  # y is odd, then add the corresponding x to r (the sum of all x's corresponding to odd y's will give the final product). Note that since we're in GF(2), the addition is in fact an XOR (very important because in GF(2) the multiplication and additions are carry-less, thus it changes the result!).
        y = y >> 1  # equivalent to y // 2
        x = x << 1  # equivalent to x*2
        if prim > 0 and x & field_charac_full:
            x = x ^ prim  # GF modulo: if x >= 256 then apply modular reduction using the primitive polynomial (we just substract, but since the primitive number can be above 256 then we directly XOR).

    return r


################### GALOIS FIELD POLYNOMIALS MATHS ###################


def gf_poly_scale(p, x):
    '''Scale a galois field polynomial with a factor x (an integer)'''
    #return _bytearray([gf_mul(p[i], x) for i in xrange(len(p))])  # unoptimized one-liner
    out = _bytearray(len(p))
    for i in range(len(p)):
        out[i] = gf_mul(p[i], x)
    return out


def gf_poly_add(p, q):
    '''Add two galois field polynomials'''
    q_len = len(q)
    r = _bytearray(max(len(p), q_len))
    r[len(r) - len(p):len(r)] = p
    #for i in xrange(len(p)):
    #r[i + len(r) - len(p)] = p[i]
    for i in xrange(q_len):
        r[i + len(r) - q_len] ^= q[i]
    return r


def gf_poly_mul(p, q):
    '''Multiply two polynomials, inside Galois Field (but the procedure is generic). Optimized function by precomputation of log.'''

    r = _bytearray(len(p) + len(q) - 1)

    lp = [gf_log[p[i]] for i in xrange(len(p))]

    for j in xrange(len(q)):
        qj = q[j]  # optimization: load the coefficient once
        if qj != 0:  # log(0) is undefined, we need to check that
            lq = gf_log[
                qj]  # Optimization: precache the logarithm of the current coefficient of q
            for i in xrange(len(p)):
                if p[i] != 0:  # log(0) is undefined, need to check that...
                    r[i + j] ^= gf_exp[
                        lp[i] +
                        lq]  # equivalent to: r[i + j] = gf_add(r[i+j], gf_mul(p[i], q[j]))
    return r


def gf_poly_mul_simple(p, q):
    '''Multiply two polynomials, inside Galois Field'''

    r = _bytearray(len(p) + len(q) - 1)

    for j in xrange(len(q)):
        for i in xrange(len(p)):
            r[i + j] ^= gf_mul(
                p[i], q[j]
            )  # equivalent to: r[i + j] = gf_add(r[i+j], gf_mul(p[i], q[j])) -- you can see it's your usual polynomial multiplication
    return r


def gf_poly_neg(poly):
    '''Returns the polynomial with all coefficients negated. In GF(2^p), negation does not change the coefficient, so we return the polynomial as-is.'''
    return poly


def gf_poly_div(dividend, divisor):
    '''Fast polynomial division by using Extended Synthetic Division and optimized for GF(2^p) computations (doesn't work with standard polynomials outside of this galois field).'''
    # CAUTION: this function expects polynomials to follow the opposite convention at decoding: the terms must go from the biggest to lowest degree (while most other functions here expect a list from lowest to biggest degree). eg: 1 + 2x + 5x^2 = [5, 2, 1], NOT [1, 2, 5]

    msg_out = _bytearray(dividend)
    divisor_len = len(divisor)
    #normalizer = divisor[0] # precomputing for performance
    for i in xrange(len(dividend) - (divisor_len - 1)):
        #msg_out[i] /= normalizer # for general polynomial division (when polynomials are non-monic), the usual way of using synthetic division is to divide the divisor g(x) with its leading coefficient (call it a). In this implementation, this means:we need to compute: coef = msg_out[i] / gen[0]. For more infos, see http://en.wikipedia.org/wiki/Synthetic_division
        coef = msg_out[i]  # precaching
        if coef != 0:  # log(0) is undefined, so we need to avoid that case explicitly (and it's also a good optimization). In fact if you remove it, it should still work because gf_mul() will take care of the condition. But it's still a good practice to put the condition here.
            for j in xrange(
                    1, divisor_len
            ):  # in synthetic division, we always skip the first coefficient of the divisior, because it's only used to normalize the dividend coefficient
                if divisor[j] != 0:  # log(0) is undefined
                    msg_out[i + j] ^= gf_mul(
                        divisor[j], coef
                    )  # equivalent to the more mathematically correct (but xoring directly is faster): msg_out[i + j] += -divisor[j] * coef

    # The resulting msg_out contains both the quotient and the remainder, the remainder being the size of the divisor (the remainder has necessarily the same degree as the divisor -- not length but degree == length-1 -- since it's what we couldn't divide from the dividend), so we compute the index where this separation is, and return the quotient and remainder.
    separator = -(divisor_len - 1)
    return msg_out[:separator], msg_out[
        separator:]  # return quotient, remainder.


def gf_poly_square(poly):  # pragma: no cover
    '''Linear time implementation of polynomial squaring. For details, see paper: "A fast software implementation for arithmetic operations in GF (2n)". De Win, E., Bosselaers, A., Vandenberghe, S., De Gersem, P., & Vandewalle, J. (1996, January). In Advances in Cryptology - Asiacrypt'96 (pp. 65-76). Springer Berlin Heidelberg.'''
    length = len(poly)
    out = _bytearray(2 * length - 1)
    for i in xrange(length - 1):
        p = poly[i]
        k = 2 * i
        if p != 0:
            #out[k] = gf_exp[(2*gf_log[p]) % field_charac] # not necessary to modulo (2^r)-1 since gf_exp is duplicated up to 510.
            out[k] = gf_exp[2 * gf_log[p]]
        #else: # not necessary since the output is already initialized to an array of 0
        #out[k] = 0
    out[2 * length - 2] = gf_exp[2 * gf_log[poly[length - 1]]]
    if out[0] == 0: out[0] = 2 * poly[1] - 1
    return out


def gf_poly_eval(poly, x):
    '''Evaluates a polynomial in GF(2^p) given the value for x. This is based on Horner's scheme for maximum efficiency.'''
    y = poly[0]
    for i in xrange(1, len(poly)):
        y = gf_mul(y, x) ^ poly[i]
    return y


################### REED-SOLOMON ENCODING ###################


def rs_generator_poly(nsym, fcr=0, generator=2):
    '''Generate an irreducible generator polynomial (necessary to encode a message into Reed-Solomon)'''
    g = _bytearray([1])
    for i in xrange(nsym):
        g = gf_poly_mul(g, [1, gf_pow(generator, i + fcr)])
    return g


def rs_generator_poly_all(max_nsym, fcr=0, generator=2):
    '''Generate all irreducible generator polynomials up to max_nsym (usually you can use n, the length of the message+ecc). Very useful to reduce processing time if you want to encode using variable schemes and nsym rates.'''

    g_all = [
        [1]
    ] * max_nsym  # a list of list is potentially faster than using a dict, since it is pre-allocated and a list has less overhead than a dict
    for nsym in xrange(max_nsym):
        g_all[nsym] = rs_generator_poly(nsym, fcr, generator)
    return g_all


def rs_simple_encode_msg(msg_in, nsym, fcr=0, generator=2, gen=None):
    '''Simple Reed-Solomon encoding (mainly an example for you to understand how it works, because it's slower than the inlined function below)'''
    global field_charac
    if (len(msg_in) + nsym) > field_charac:
        raise ValueError("Message is too long (%i when max is %i)" %
                         (len(msg_in) + nsym, field_charac))
    if gen is None: gen = rs_generator_poly(nsym, fcr, generator)

    # Pad the message, then divide it by the irreducible generator polynomial
    _, remainder = gf_poly_div(msg_in + _bytearray(len(gen) - 1), gen)
    # The remainder is our RS code! Just append it to our original message to get our full codeword (this represents a polynomial of max 256 terms)
    msg_out = msg_in + remainder
    # Return the codeword
    return msg_out


def rs_encode_msg(msg_in, nsym, fcr=0, generator=2, gen=None):
    '''Reed-Solomon main encoding function, using polynomial division (Extended Synthetic Division, the fastest algorithm available to my knowledge), better explained at http://research.swtch.com/field'''
    global field_charac
    if (len(msg_in) + nsym) > field_charac:
        raise ValueError("Message is too long (%i when max is %i)" %
                         (len(msg_in) + nsym, field_charac))
    if gen is None: gen = rs_generator_poly(nsym, fcr, generator)

    msg_in = _bytearray(msg_in)
    msg_out = _bytearray(msg_in) + _bytearray(
        len(gen) - 1
    )  # init msg_out with the values inside msg_in and pad with len(gen)-1 bytes (which is the number of ecc symbols).

    # Precompute the logarithm of every items in the generator
    lgen = _bytearray([gf_log[gen[j]] for j in xrange(len(gen))])

    # Cache lengths for faster access inside loops
    msg_in_len = len(msg_in)
    gen_len = len(gen)

    for i in xrange(msg_in_len):
        coef = msg_out[i]
        if coef != 0:
            lcoef = gf_log[coef]  # precaching

            for j in xrange(1, gen_len):
                msg_out[i + j] ^= gf_exp[lcoef + lgen[
                    j]]  # optimization, equivalent to gf_mul(gen[j], msg_out[i]) and we just substract it to msg_out[i+j] (but since we are in GF256, it's equivalent to an addition and to an XOR). In other words, this is simply a "multiply-accumulate operation"

    # Recopy the original message bytes (overwrites the part where the quotient was computed)
    msg_out[:
            msg_in_len] = msg_in  # equivalent to c = mprime - b, where mprime is msg_in padded with [0]*nsym
    return msg_out


################### REED-SOLOMON DECODING ###################


def rs_calc_syndromes(msg, nsym, fcr=0, generator=2):
    '''Given the received codeword msg and the number of error correcting symbols (nsym), computes the syndromes polynomial.
    Mathematically, it's essentially equivalent to a Fourrier Transform (Chien search being the inverse).
    '''

    return [0] + [
        gf_poly_eval(msg, gf_pow(generator, i + fcr)) for i in xrange(nsym)
    ]


def rs_correct_errata(msg_in, synd, err_pos, fcr=0, generator=2):
    '''Forney algorithm, computes the values (error magnitude) to correct the input message.'''
    global field_charac
    msg = _bytearray(msg_in)
    coef_pos = [len(msg) - 1 - p for p in err_pos]
    err_loc = rs_find_errata_locator(coef_pos, generator)
    err_eval = rs_find_error_evaluator(synd[::-1], err_loc,
                                       len(err_loc) - 1)[::-1]

    X = _bytearray(len(coef_pos))  # will store the position of the errors
    for i in xrange(len(coef_pos)):
        l = field_charac - coef_pos[i]
        X[i] = gf_pow(generator, -l)

    E = _bytearray(len(msg))
    X_len = len(X)
    for i, Xi in enumerate(X):

        Xi_inv = gf_inverse(Xi)

        err_loc_prime = 1
        for j in xrange(X_len):
            if j != i:
                err_loc_prime = gf_mul(err_loc_prime,
                                       gf_sub(1, gf_mul(Xi_inv, X[j])))

        if err_loc_prime == 0:
            raise ReedSolomonError(
                "Decoding failed: Forney algorithm could not properly detect where the errors are located (errata locator prime is 0)."
            )

        y = gf_poly_eval(
            err_eval[::-1], Xi_inv
        )  # numerator of the Forney algorithm (errata evaluator evaluated)
        y = gf_mul(gf_pow(Xi, 1 - fcr), y)  # adjust to fcr parameter

        # Compute the magnitude
        magnitude = gf_div(
            y, err_loc_prime
        )  # magnitude value of the error, calculated by the Forney algorithm (an equation in fact): dividing the errata evaluator with the errata locator derivative gives us the errata magnitude (ie, value to repair) the ith symbol
        E[err_pos[i]] = magnitude
    msg = gf_poly_add(
        msg, E
    )  # equivalent to Ci = Ri - Ei where Ci is the correct message, Ri the received (senseword) message, and Ei the errata magnitudes (minus is replaced by XOR since it's equivalent in GF(2^p)). So in fact here we substract from the received message the errors magnitude, which logically corrects the value to what it should be.
    return msg


def rs_find_error_locator(synd, nsym, erase_loc=None, erase_count=0):
    '''Find error/errata locator and evaluator polynomials with Berlekamp-Massey algorithm'''

    if erase_loc:  # if the erasure locator polynomial is supplied, we init with its value, so that we include erasures in the final locator polynomial
        err_loc = _bytearray(erase_loc)
        old_loc = _bytearray(erase_loc)
    else:
        err_loc = _bytearray(
            [1]
        )  # This is the main variable we want to fill, also called Sigma in other notations or more formally the errors/errata locator polynomial.
        old_loc = _bytearray([1])
    synd_shift = 0
    if len(synd) > nsym: synd_shift = len(synd) - nsym

    for i in xrange(
            nsym - erase_count
    ):  # generally: nsym-erase_count == len(synd), except when you input a partial erase_loc and using the full syndrome instead of the Forney syndrome, in which case nsym-erase_count is more correct (len(synd) will fail badly with IndexError).
        if erase_loc:  # if an erasures locator polynomial was provided to init the errors locator polynomial, then we must skip the FIRST erase_count iterations (not the last iterations, this is very important!)
            K = erase_count + i + synd_shift
        else:  # if erasures locator is not provided, then either there's no erasures to account or we use the Forney syndromes, so we don't need to use erase_count nor erase_loc (the erasures have been trimmed out of the Forney syndromes).
            K = i + synd_shift

        delta = synd[K]
        for j in xrange(
                1, len(err_loc)
        ):  # range 1:256 is important: if you use range 0:255, if the last byte of the ecc symbols is corrupted, it won't be correctable! You need to use the range 1,256 to include this last byte.
            delta ^= gf_mul(err_loc[-(j + 1)], synd[K - j])
        old_loc = old_loc + _bytearray([0])

        # Iteratively estimate the errata locator and evaluator polynomials
        if delta != 0:  # Update only if there's a discrepancy
            if len(old_loc) > len(err_loc):
                new_loc = gf_poly_scale(old_loc, delta)
                old_loc = gf_poly_scale(
                    err_loc, gf_inverse(delta)
                )  # effectively we are doing err_loc * 1/delta = err_loc // delta
                err_loc = new_loc

            err_loc = gf_poly_add(err_loc, gf_poly_scale(old_loc, delta))

    for i, x in enumerate(err_loc):
        if x != 0:
            err_loc = err_loc[i:]
            break
    errs = len(err_loc) - 1
    if (
            errs - erase_count
    ) * 2 + erase_count > nsym:  # failure if we have too many erratas for the Singleton Bound.
        raise ReedSolomonError("Too many errors to correct")

    # Return result
    return err_loc


def rs_find_errata_locator(e_pos, generator=2):
    '''Compute the erasures/errors/errata locator polynomial from the erasures/errors/errata positions (the positions must be relative to the x coefficient, eg: "hello worldxxxxxxxxx" is tampered to "h_ll_ worldxxxxxxxxx" with xxxxxxxxx being the ecc of length n-k=9, here the string positions are [1, 4], but the coefficients are reversed since the ecc characters are placed as the first coefficients of the polynomial, thus the coefficients of the erased characters are n-1 - [1, 4] = [18, 15] = erasures_loc to be specified as an argument.'''
    e_loc = [1]
    for i in e_pos:
        e_loc = gf_poly_mul(
            e_loc, gf_poly_add(_bytearray([1]), [gf_pow(generator, i), 0]))
    return e_loc


def rs_find_error_evaluator(synd, err_loc, nsym):
    '''Compute the error (or erasures if you supply sigma=erasures locator polynomial, or errata) evaluator polynomial Omega from the syndrome and the error/erasures/errata locator Sigma. Omega is already computed at the same time as Sigma inside the Berlekamp-Massey implemented above, but in case you modify Sigma, you can recompute Omega afterwards using this method, or just ensure that Omega computed by BM is correct given Sigma.'''
    remainder = gf_poly_mul(synd, err_loc)
    remainder = remainder[len(remainder) - (nsym + 1):]

    return remainder


def rs_find_errors(err_loc, nmess, generator=2):
    '''Find the roots (ie, where evaluation = zero) of error polynomial by smart bruteforce trial. This is a faster form of chien search, processing only useful coefficients (the ones in the messages) instead of the whole 2^8 range. Besides the speed boost, this also allows to fix a number of issue: correctly decoding when the last ecc byte is corrupted, and accepting messages of length n > 2^8.'''
    err_pos = []
    for i in xrange(nmess):
        if gf_poly_eval(err_loc, gf_pow(generator, i)) == 0:
            err_pos.append(nmess - 1 - i)
    errs = len(err_loc) - 1
    if len(err_pos) != errs:
        # TODO: to decode messages+ecc with length n > 255, we may try to use a bruteforce approach: the correct positions ARE in the final array j, but the problem is because we are above the Galois Field's range, there is a wraparound so that for example if j should be [0, 1, 2, 3], we will also get [255, 256, 257, 258] (because 258 % 255 == 3, same for the other values), so we can't discriminate. The issue is that fixing any errs_nb errors among those will always give a correct output message (in the sense that the syndrome will be all 0), so we may not even be able to check if that's correct or not, so I'm not sure the bruteforce approach may even be possible.
        raise ReedSolomonError(
            "Too many (or few) errors found by Chien Search for the errata locator polynomial!"
        )
    return _bytearray(err_pos)


def rs_forney_syndromes(synd, pos, nmess, generator=2):
    # Compute Forney syndromes, which computes a modified syndromes to compute only errors (erasures are trimmed out). Do not confuse this with Forney algorithm, which allows to correct the message based on the location of errors.
    erase_pos_reversed = [
        nmess - 1 - p for p in pos
    ]  # prepare the coefficient degree positions (instead of the erasures positions)

    # Optimized method, all operations are inlined
    fsynd = list(
        synd[1:]
    )  # make a copy and trim the first coefficient which is always 0 by definition
    for i in xrange(len(pos)):
        x = gf_pow(generator, erase_pos_reversed[i])
        for j in xrange(len(fsynd) - 1):
            fsynd[j] = gf_mul(fsynd[j], x) ^ fsynd[j + 1]
        #fsynd.pop() # useless? it doesn't change the results of computations to leave it there

    return fsynd


def rs_correct_msg(msg_in,
                   nsym,
                   fcr=0,
                   generator=2,
                   erase_pos=None,
                   only_erasures=False):
    '''Reed-Solomon main decoding function'''
    global field_charac
    if len(msg_in) > field_charac:
        # Note that it is in fact possible to encode/decode messages that are longer than field_charac, but because this will be above the field, this will generate more error positions during Chien Search than it should, because this will generate duplicate values, which should normally be prevented thank's to the prime polynomial reduction (eg, because it can't discriminate between error at position 1 or 256, both being exactly equal under galois field 2^8). So it's really not advised to do it, but it's possible (but then you're not guaranted to be able to correct any error/erasure on symbols with a position above the length of field_charac -- if you really need a bigger message without chunking, then you should better enlarge c_exp so that you get a bigger field).
        raise ValueError("Message is too long (%i when max is %i)" %
                         (len(msg_in), field_charac))

    msg_out = _bytearray(msg_in)  # copy of message
    # erasures: set them to null bytes for easier decoding (but this is not necessary, they will be corrected anyway, but debugging will be easier with null bytes because the error locator polynomial values will only depend on the errors locations, not their values)
    if erase_pos is None:
        erase_pos = _bytearray()
    else:
        if isinstance(erase_pos,
                      list):  # ensure we use a bytearray, not a list
            erase_pos = _bytearray(erase_pos)
        for e_pos in erase_pos:
            msg_out[e_pos] = 0
    # check if there are too many erasures to correct (beyond the Singleton bound)
    if len(erase_pos) > nsym:
        raise ReedSolomonError("Too many erasures to correct")
    # prepare the syndrome polynomial using only errors (ie: errors = characters that were either replaced by null byte or changed to another character, but we don't know their positions)
    synd = rs_calc_syndromes(msg_out, nsym, fcr, generator)
    # check if there's any error/erasure in the input codeword. If not (all syndromes coefficients are 0), then just return the codeword as-is.
    if max(synd) == 0:
        return msg_out[:-nsym], msg_out[-nsym:], erase_pos  # no errors

    # Find errors locations
    if only_erasures:
        err_pos = _bytearray()
    else:
        # compute the Forney syndromes, which hide the erasures from the original syndrome (so that BM will just have to deal with errors, not erasures)
        fsynd = rs_forney_syndromes(synd, erase_pos, len(msg_out), generator)
        # compute the error locator polynomial using Berlekamp-Massey
        err_loc = rs_find_error_locator(fsynd,
                                        nsym,
                                        erase_count=len(erase_pos))
        # locate the message errors using Chien search (or bruteforce search)
        err_pos = rs_find_errors(err_loc[::-1], len(msg_out), generator)
        if err_pos is None:
            raise ReedSolomonError("Could not locate error")

    # Find errors values and apply them to correct the message
    # compute errata evaluator and errata magnitude polynomials, then correct errors and erasures
    msg_out = rs_correct_errata(
        msg_out, synd, erase_pos + err_pos, fcr, generator
    )  # note that we here use the original syndrome, not the forney syndrome (because we will correct both errors and erasures, so we need the full syndrome)
    # check if the final message is fully repaired
    synd = rs_calc_syndromes(msg_out, nsym, fcr, generator)
    if max(synd) > 0:
        raise ReedSolomonError("Could not correct message")
    # return the successfully decoded message
    return msg_out[:-nsym], msg_out[
        -nsym:], erase_pos + err_pos  # also return the corrected ecc block so that the user can check(), and the position of errors to allow for adaptive bitrate algorithm to check how the number of errors vary


def rs_correct_msg_nofsynd(msg_in,
                           nsym,
                           fcr=0,
                           generator=2,
                           erase_pos=None,
                           only_erasures=False):
    '''Reed-Solomon main decoding function, without using the modified Forney syndromes'''
    global field_charac
    if len(msg_in) > field_charac:
        raise ValueError("Message is too long (%i when max is %i)" %
                         (len(msg_in), field_charac))

    msg_out = _bytearray(msg_in)  # copy of message
    # erasures: set them to null bytes for easier decoding (but this is not necessary, they will be corrected anyway, but debugging will be easier with null bytes because the error locator polynomial values will only depend on the errors locations, not their values)
    if erase_pos is None:
        erase_pos = _bytearray()
    else:
        if isinstance(erase_pos,
                      list):  # ensure we use a bytearray, not a list
            erase_pos = _bytearray(erase_pos)
        for e_pos in erase_pos:
            msg_out[e_pos] = 0
    # check if there are too many erasures
    if len(erase_pos) > nsym:
        raise ReedSolomonError("Too many erasures to correct")
    # prepare the syndrome polynomial using only errors (ie: errors = characters that were either replaced by null byte or changed to another character, but we don't know their positions)
    synd = rs_calc_syndromes(msg_out, nsym, fcr, generator)
    # check if there's any error/erasure in the input codeword. If not (all syndromes coefficients are 0), then just return the codeword as-is.
    if max(synd) == 0:
        return msg_out[:-nsym], msg_out[-nsym:], []  # no errors

    # prepare erasures locator and evaluator polynomials
    erase_loc = None
    #erase_eval = None
    erase_count = 0
    if erase_pos:
        erase_count = len(erase_pos)
        msg_out_len = len(msg_out)  # cache to avoid recalculations inside loop
        erase_pos_reversed = [msg_out_len - 1 - eras for eras in erase_pos]
        erase_loc = rs_find_errata_locator(erase_pos_reversed,
                                           generator=generator)
        #erase_eval = rs_find_error_evaluator(synd[::-1], erase_loc, len(erase_loc)-1)

    # prepare errors/errata locator polynomial
    if only_erasures:
        err_loc = erase_loc[::-1]
        #err_eval = erase_eval[::-1]
    else:
        err_loc = rs_find_error_locator(synd,
                                        nsym,
                                        erase_loc=erase_loc,
                                        erase_count=erase_count)
        err_loc = err_loc[::-1]
        #err_eval = rs_find_error_evaluator(synd[::-1], err_loc[::-1], len(err_loc)-1)[::-1] # find error/errata evaluator polynomial (not really necessary since we already compute it at the same time as the error locator poly in BM)

    # locate the message errors
    err_pos = rs_find_errors(
        err_loc, len(msg_out), generator
    )  # find the roots of the errata locator polynomial (ie: the positions of the errors/errata)
    if err_pos is None:
        raise ReedSolomonError("Could not locate error")

    # compute errata evaluator and errata magnitude polynomials, then correct errors and erasures
    msg_out = rs_correct_errata(msg_out,
                                synd,
                                err_pos,
                                fcr=fcr,
                                generator=generator)
    # check if the final message is fully repaired
    synd = rs_calc_syndromes(msg_out, nsym, fcr, generator)
    if max(synd) > 0:
        raise ReedSolomonError("Could not correct message")
    # return the successfully decoded message
    return msg_out[:-nsym], msg_out[
        -nsym:], erase_pos + err_pos  # also return the corrected ecc block so that the user can check(), and the position of errors to allow for adaptive bitrate algorithm to check how the number of errors vary


def rs_check(msg, nsym, fcr=0, generator=2):
    '''Returns true if the message + ecc has no error of false otherwise (may not always catch a wrong decoding or a wrong message, particularly if there are too many errors -- above the Singleton bound --, but it usually does)'''
    return (max(rs_calc_syndromes(msg, nsym, fcr, generator)) == 0)


class RSCodec(object):

    def __init__(self,
                 nsym=10,
                 nsize=255,
                 fcr=0,
                 prim=0x11d,
                 generator=2,
                 c_exp=8,
                 single_gen=True):

        # Auto-setup if galois field or message length is different than default (exponent 8)
        if nsize > 255 and c_exp <= 8:  # nsize (chunksize) is larger than the galois field, we resize the galois field
            # Get the next closest power of two
            c_exp = int(
                math.log(2**(math.floor(math.log(nsize) / math.log(2)) + 1),
                         2))
        if c_exp != 8 and prim == 0x11d:  # prim was not correctly defined, find one
            prim = find_prime_polys(generator=generator,
                                    c_exp=c_exp,
                                    fast_primes=True,
                                    single=True)[0]
            if nsize == 255:  # resize chunk size if not set
                nsize = int(2**c_exp - 1)
        if nsym >= nsize:
            raise ValueError(
                'ECC symbols must be strictly less than the total message length (nsym < nsize).'
            )

        # Memorize variables
        self.nsym = nsym  # number of ecc symbols (ie, the repairing rate will be r=(nsym/2)/nsize, so for example if you have nsym=5 and nsize=10, you have a rate r=0.25, so you can correct up to 0.25% errors (or exactly 2 symbols out of 10), and 0.5% erasures (5 symbols out of 10).
        self.nsize = nsize  # maximum length of one chunk (ie, message + ecc symbols after encoding, for the message alone it's nsize-nsym)
        self.fcr = fcr  # first consecutive root, can be any value between 0 and (2**c_exp)-1
        self.prim = prim  # prime irreducible polynomial, use find_prime_polys() to find a prime poly
        self.generator = generator  # generator integer, must be prime
        self.c_exp = c_exp  # exponent of the field's characteristic. This both defines the maximum value per symbol and the maximum length of one chunk. By default it's GF(2^8), do not change if you're not sure what it means.

        # Initialize the look-up tables for easy and quick multiplication/division
        self.gf_log, self.gf_exp, self.field_charac = init_tables(
            prim, generator, c_exp)
        # Precompute the generator polynomials
        if single_gen:
            self.gen = {}
            self.gen[nsym] = rs_generator_poly(nsym,
                                               fcr=fcr,
                                               generator=generator)
        else:
            self.gen = rs_generator_poly_all(nsize,
                                             fcr=fcr,
                                             generator=generator)

    def chunk(self, data, chunk_size):
        '''Split a long message into chunks
        DEPRECATED: inlined alternate form so that we can preallocate arrays and hence get faster results with JIT compilers such as PyPy.'''
        for i in xrange(0, len(data), chunk_size):
            # alternative chunking form: j = i*chunk_size; chunk = data[j:j+chunk_size]
            # Split the long message in a chunk
            chunk = data[i:i + chunk_size]
            yield chunk

    '''Encode a message using Reed-Solomon algorithm'''

    def encode(self, data, nsym=None):
        # Restore precomputed tables (allow to use multiple RSCodec in one script)
        global gf_log, gf_exp, field_charac
        gf_log, gf_exp, field_charac = self.gf_log, self.gf_exp, self.field_charac
        nsize, fcr, generator = self.nsize, self.fcr, self.generator

        if not nsym:
            nsym = self.nsym
        gen = self.gen[nsym]

        if isinstance(data, str):
            data = _bytearray(data)

        # Calculate chunk size and total number of chunks for looping
        chunk_size = int(nsize - nsym)
        total_chunks = int(
            math.ceil(float(len(data)) / float(chunk_size))
        )  # need to convert to floats first to get an accurate floating division, or else we assume implicit conversion and it will cause an error on Python 2

        # Preallocate output array
        enc = _bytearray(
            total_chunks * nsize
        )  # pre-allocate array and we will overwrite data in it, much faster than extending
        # Chunking loop
        for i in xrange(0, total_chunks):
            # Encode this chunk and update a slice of the output bytearray, much more efficient than extending an array constantly
            enc[i * nsize:(i + 1) * nsize] = rs_encode_msg(
                data[i * chunk_size:(i + 1) * chunk_size],
                nsym,
                fcr=fcr,
                generator=generator,
                gen=gen)
        return enc

    '''Decode a message using Reed-Solomon algorithm'''

    def decode(self, data, nsym=None, erase_pos=None, only_erasures=False):

        global gf_log, gf_exp, field_charac
        gf_log, gf_exp, field_charac = self.gf_log, self.gf_exp, self.field_charac

        if isinstance(data, str):
            data = _bytearray(data)
        if isinstance(erase_pos, list):
            erase_pos = _bytearray(erase_pos)

        # Precache class attributes into local variables
        if not nsym:
            nsym = self.nsym
        nsize = self.nsize
        fcr = self.fcr
        generator = self.generator

        # Calculate chunk size and total number of chunks for looping
        chunk_size = nsize
        total_chunks = int(
            math.ceil(float(len(data)) / float(chunk_size))
        )  # need to convert to floats first to get an accurate floating division, or else we assume implicit conversion and it will cause an error on Python 2
        nmes = int(nsize - nsym)

        # Initialize output array
        dec = _bytearray(
            total_chunks * nmes
        )  # pre-allocate array and we will overwrite data in it, much faster than extending
        dec_full = _bytearray(total_chunks * nsize)
        errata_pos_all = _bytearray()
        # Chunking loop
        for i in xrange(0, total_chunks):  # Split the long message in a chunk
            # Extract the erasures for this chunk
            if erase_pos is not None:
                # First extract the erasures for this chunk (all erasures below the maximum chunk length)
                e_pos = [x for x in erase_pos if x < nsize]
                # Then remove the extract erasures from the big list and also decrement all subsequent positions values by nsize (the current chunk's size) so as to prepare the correct alignment for the next iteration
                erase_pos = [x - nsize for x in erase_pos if x >= nsize]
            else:
                e_pos = _bytearray()
            # Decode/repair this chunk!
            rmes, recc, errata_pos = rs_correct_msg(
                data[i * chunk_size:(i + 1) * chunk_size],
                nsym,
                fcr=fcr,
                generator=generator,
                erase_pos=e_pos,
                only_erasures=only_erasures)
            dec[i * nmes:(i + 1) * nmes] = rmes
            dec_full[i * nsize:(i + 1) * nsize] = rmes
            dec_full[
                i * nsize + nmes:(i + 1) * nsize +
                nmes] = recc  # append corrected ecc just after corrected message. The two lines are equivalent to rmes + recc but here we don't need to concatenate both arrays first (and create a third one for nothing) before storing in the output array
            errata_pos_all.extend(errata_pos)
        return dec, dec_full, errata_pos_all

    def check(self, data, nsym=None):
        '''Check if a message+ecc stream is not corrupted (or fully repaired). Note: may return a wrong result if number of errors > nsym.'''
        if not nsym:
            nsym = self.nsym
        if isinstance(data, str):
            data = _bytearray(data)

        # Precache class attributes into local variables
        nsize = self.nsize
        fcr = self.fcr
        generator = self.generator

        # Calculate chunksize
        chunk_size = nsize
        total_chunks = int(
            math.ceil(float(len(data)) / float(chunk_size))
        )  # need to convert to floats first to get an accurate floating division, or else we assume implicit conversion and it will cause an error on Python 2

        # Pre-allocate output array
        check = [
            False
        ] * total_chunks  # TODO: could use a bitarray but this creates an external dependency and it's not compatible with cython https://pypi.org/project/bitarray/ and https://www.noveltech.dev/booleans-python-numpy/
        # Chunking loop
        for i in xrange(0, total_chunks):  # Split the long message in a chunk
            check[i] = rs_check(data[i * chunk_size:(i + 1) * chunk_size],
                                nsym,
                                fcr=fcr,
                                generator=generator)
        return check

    def maxerrata(self, nsym=None, errors=None, erasures=None, verbose=False):
        if not nsym:
            nsym = self.nsym
        maxerrors = int(nsym / 2)
        maxerasures = nsym
        if erasures is not None and erasures >= 0:
            if erasures > maxerasures:
                raise ReedSolomonError(
                    "Specified number of errors or erasures exceeding the Singleton Bound!"
                )
            maxerrors = int((nsym - erasures) / 2)
            if verbose:
                print(
                    'This codec can correct up to %i errors and %i erasures simultaneously'
                    % (maxerrors, erasures))
            return maxerrors, erasures
        if errors is not None and errors >= 0:
            if errors > maxerrors:
                raise ReedSolomonError(
                    "Specified number of errors or erasures exceeding the Singleton Bound!"
                )
            maxerasures = int(nsym - (errors * 2))
            if verbose:
                print(
                    'This codec can correct up to %i errors and %i erasures simultaneously'
                    % (errors, maxerasures))
            # Return a tuple with the maximum number of simultaneously corrected errors and erasures
            return errors, maxerasures
        # Return a tuple with the maximum number of errors and erasures (independently corrected)
        if verbose:
            print(
                'This codec can correct up to %i errors and %i erasures independently'
                % (maxerrors, maxerasures))
        return maxerrors, maxerasures