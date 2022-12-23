#include <bits/stdc++.h>
using namespace std;

/**
 * @brief BigInt Class
 * Default constructor
 * • At least 2 additional constructors
 * • Copy constructor
 * • Overloaded Operator (at least 2)
 * • Overloaded =
 * • Overloaded (), []
 * • Destructor
 */
class BigInt
{
private:
    string num;
    bool sign;

    // Helper function
    // add and subtract
    string add(string a, string b)
    {
        string res = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            sum += carry;
            res += to_string(sum % 10);
            carry = sum / 10;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string subtract(string a, string b)
    {
        string res = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum -= b[j] - '0';
            sum -= carry;
            if (sum < 0)
            {
                sum += 10;
                carry = 1;
            }
            else
                carry = 0;
            res += to_string(sum);
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    // default constructor
    BigInt()
    {
        num = "0";
        sign = false;
    }

    // constructor
    BigInt(string s)
    {
        if (s[0] == '-')
        {
            sign = true;
            num = s.substr(1);
        }
        else
        {
            sign = false;
            num = s;
        }
    }

    BigInt(string s, bool sign)
    {
        this->sign = sign;
        num = s;
    }

    // copy constructor
    BigInt(const BigInt &b)
    {
        num = b.num;
        sign = b.sign;
    }

    // overloaded operator +
    BigInt operator+(const BigInt &b)
    {
        BigInt res;
        if (sign == b.sign)
        {
            res.sign = sign;
            res.num = add(num, b.num);
        }
        else
        {
            if (num == b.num)
            {
                res.num = "0";
                res.sign = false;
            }
            else if (num > b.num)
            {
                res.sign = sign;
                res.num = subtract(num, b.num);
            }
            else
            {
                res.sign = b.sign;
                res.num = subtract(b.num, num);
            }
        }
        return res;
    }

    // overloaded operator -
    BigInt operator-(const BigInt &b)
    {
        BigInt res;
        if (sign != b.sign)
        {
            res.sign = sign;
            res.num = add(num, b.num);
        }
        else
        {
            if (num == b.num)
            {
                res.num = "0";
                res.sign = false;
            }
            else if (num > b.num)
            {
                res.sign = sign;
                res.num = subtract(num, b.num);
            }
            else
            {
                res.sign = !b.sign;
                res.num = subtract(b.num, num);
            }
        }
        return res;
    }

    // overloaded operator ==
    bool operator==(const BigInt &b)
    {
        return (num == b.num && sign == b.sign);
    }

    // overloaded operator ()
    string operator()(int i)
    {
        return num.substr(i);
    }

    // overloaded operator []
    char operator[](int i)
    {
        return num[i];
    }

    // destructor
    ~BigInt()
    {
        num = "";
        sign = false;
    }
};

int main()
{
    BigInt a("123456789");
    BigInt b("987654321");
    BigInt c = a + b;
    BigInt d = a - b;

    BigInt e("82865872642");
    BigInt f("82865872642");

    BigInt g("78242876424", false);
    BigInt h("7825642876424", true);

    BigInt i = h + g;
    BigInt j = h - g;

    // e==f
    cout << (e == f) << endl;

    // [] operator
    cout << e[0] << endl;

    // print
    cout << "a: " << a(0) << endl;
    cout << "b: " << b(0) << endl;
    cout << "c: " << c(0) << endl;
    cout << "d: " << d(0) << endl;
    cout << "e: " << e(0) << endl;
    cout << "f: " << f(0) << endl;
    cout << "g: " << g(0) << endl;
    cout << "h: " << h(0) << endl;
    cout << "i: " << i(0) << endl;
    cout << "j: " << j(0) << endl;
    return 0;
}