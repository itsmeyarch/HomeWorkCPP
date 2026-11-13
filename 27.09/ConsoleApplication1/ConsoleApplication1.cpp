#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (denominator == 0) {
            denominator = 1;
            return;
        }
        int a = std::abs(numerator);
        int b = std::abs(denominator);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;
        if (gcd != 0) {
            numerator /= gcd;
            denominator /= gcd;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    explicit Fraction(int num, int den = 1) : numerator(num), denominator(den) {
        simplify();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    void setNumerator(int num) {
        numerator = num;
        simplify();
    }

    void setDenominator(int den) {
        denominator = den;
        simplify();
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator*(int num) const {
        return Fraction(numerator * num, denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator/(int num) const {
        return Fraction(numerator, denominator * num);
    }

    void print() const {
        std::cout << numerator << "/" << denominator << "\n";
    }
};

inline Fraction operator*(int num, const Fraction& frac) {
    return Fraction(num * frac.getNumerator(), frac.getDenominator());
}

inline Fraction operator/(int num, const Fraction& frac) {
    return Fraction(num * frac.getDenominator(), frac.getNumerator());
}

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction r1 = f1 * f2;
    Fraction r2 = 2 * f1;
    Fraction r3 = f1 * 3;

    Fraction r4 = f1 / f2;
    Fraction r5 = 1 / f1;
    Fraction r6 = f1 / 2;

    r1.print();
    r2.print();
    r3.print();
    r4.print();
    r5.print();
    r6.print();
}