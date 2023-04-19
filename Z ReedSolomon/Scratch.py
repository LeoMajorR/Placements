import numpy as np


def reed_solomon_encode(message, n, k):
    """Encodes a message using Reed-Solomon encoding.

 Args:
 message: A NumPy array of shape (k,) containing the message to be encoded.
 n: The length of the codeword.
 k: The number of message symbols.

 Returns:
 A NumPy array of shape (n,) containing the encoded codeword.
 """

    # Compute the generator polynomial.
    g = np.polynomial.Polynomial(np.arange(n)) % 2**n

    # Compute the syndrome polynomial.
    syndrome = np.polynomial.Polynomial(message) % 2**n

    # Compute the error locator polynomial.
    e = np.polynomial.Polynomial(syndrome) % 2**n

    # Compute the error polynomial.
    e = np.polynomial.Polynomial(e) % 2**n

    # Compute the error correction polynomial.
    c = g**e

    # Compute the encoded codeword.
    codeword = message + c

    return codeword


def reed_solomon_decode(codeword, n, k):
    """Decodes a codeword using Reed-Solomon decoding.

 Args:
 codeword: A NumPy array of shape (n,) containing the codeword to be decoded.
 n: The length of the codeword.
 k: The number of message symbols.

 Returns:
 A NumPy array of shape (k,) containing the decoded message.
 """

    # Compute the generator polynomial.
    g = np.polynomial.Polynomial(np.arange(n)) % 2**n

    # Compute the syndrome polynomial.
    syndrome = np.polynomial.Polynomial(codeword) % 2**n

    # Compute the error locator polynomial.
    e = np.polynomial.Polynomial(syndrome) % 2**n

    # Compute the error polynomial.
    e = np.polynomial.Polynomial(e) % 2**n

    # Compute the error correction polynomial.
    c = g**e

    # Compute the decoded message.
    message = codeword - c

    return message


if __name__ == "__main__":
    # Define the message and codeword length.
    message = np.array([1, 0, 1, 0, 1, 0, 1, 0, 1, 0])
    n = 15
    k = 10

    # Encode the message.
    codeword = reed_solomon_encode(message, n, k)
    print(f"The encoded codeword is: {codeword}")

    # Simulate a burst error.
    codeword[0] = 1

    # Decode the codeword.
    message = reed_solomon_decode(codeword, n, k)
    print(f"The decoded message is: {message}")