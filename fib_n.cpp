#include <iostream>

using namespace std;

class BigInt {
    string num;
    public:
        BigInt(unsigned long long n = 0);
    BigInt(BigInt & );
    friend void divideByTwo(BigInt & a);
    friend int Length(const BigInt & );
    BigInt & operator = (const BigInt & );
    friend BigInt & operator += (BigInt & ,
        const BigInt & );
    friend ostream & operator << (ostream & ,
        const BigInt & );
    friend BigInt getNthFibNum(int n);
};

BigInt::BigInt(unsigned long long nr) {
    do {
        num.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(BigInt & a) {
    num = a.num;
}
int Length(const BigInt & a) {
    return a.num.size();
}

BigInt & BigInt::operator = (const BigInt & a) {
    num = a.num;
    return * this;
}

BigInt & operator += (BigInt & a,
    const BigInt & b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.num.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.num[i] + b.num[i]) + t;
        else
            s = a.num[i] + t;
        t = s / 10;
        a.num[i] = (s % 10);
    }
    if (t)
        a.num.push_back(t);
    return a;
}
BigInt operator + (const BigInt & a,
    const BigInt & b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

void divideByTwo(BigInt & a) {
    int add = 0;
    for (int i = a.num.size() - 1; i >= 0; i--) {
        int digit = (a.num[i] >> 1) + add;
        add = ((a.num[i] & 1) * 5);
        a.num[i] = digit;
    }
    while (a.num.size() > 1 && !a.num.back())
        a.num.pop_back();
}

BigInt getNthFibNum(int n) {
    BigInt a(1), b(1), c;
    if (!n)
        return c;
    n--;
    while (n--) {
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}

ostream & operator << (ostream & out,
    const BigInt & a) {
    for (int i = a.num.size() - 1; i >= 0; i--)
        cout << (short) a.num[i];
    return cout;
}
