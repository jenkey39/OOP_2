#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class TComplex {
private:
    double real;
    double imag;

public:
    TComplex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    TComplex(const TComplex& other) : real(other.real), imag(other.imag) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    TComplex& operator=(const TComplex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    TComplex operator+(const TComplex& other) const {
        return TComplex(real + other.real, imag + other.imag);
    }

    TComplex operator-(const TComplex& other) const {
        return TComplex(real - other.real, imag - other.imag);
    }

    TComplex operator*(const TComplex& other) const {
        return TComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    TComplex operator/(const TComplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return TComplex((real * other.real + imag * other.imag) / denominator,
                        (imag * other.real - real * other.imag) / denominator);
    }

    bool operator==(const TComplex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const TComplex& other) const {
        return !(*this == other);
    }

    // Для ввода и вывода комплексных чисел
    friend std::istream& operator>>(std::istream& in, TComplex& complex) {
        std::cout << "Введите действительную часть: ";
        in >> complex.real;
        std::cout << "Введите мнимую часть: ";
        in >> complex.imag;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const TComplex& complex) {
        out << complex.real;
        if (complex.imag >= 0) {
            out << " + " << complex.imag << "i";
        } else {
            out << " - " << -complex.imag << "i";
        }
        return out;
    }

    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }
};

#endif
