#include <cmath>
#include <iostream>

export module Math;

export namespace Math {
    export  class Complex
    {
    public:
        //конструкторы
        Complex()
        {
            m_mod = m_arg = 0;
        }
        Complex(double a)
        {
            m_mod = a;
            m_arg = 0.0;
        }
        Complex(double real, double image)
        {
            m_mod = sqrt(real * real + image * image);
            m_arg = atan2(image, real);
            if (m_mod < 6.6613381477509392e-15)
                m_mod = 0;
            if ((m_arg > 3.1415926535897) && (m_arg < 3.1415926535898))
                m_arg = 0;
        }
        //статические методы static
        static Complex FromExponentialForm(double m_mod, double m_arg)
        {
            return Complex(m_mod * cos(m_arg), m_mod * sin(m_arg));
        }
        static Complex FromAlgebraicForm(double m_mod, double m_arg)
        {
            return Complex(m_mod, m_arg);
        }
        double Re() const
        {
            return m_mod * cos(m_arg);
        }
        double Im() const
        {
            return m_mod * sin(m_arg);
        }
        double Mod() const{ return m_mod; }
        double Arg() const { return m_arg; }

        explicit operator double() { return Re(); }

        Complex operator-() { return Complex(-this->m_mod * cos(this->m_arg), -this->m_mod * sin(this->m_arg)); }
        Complex& operator++()
        {
            double m_re = Re() + 1;           
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);            
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex operator++(int pepe)
        {
            Complex result(*this);          
            double m_re = Re() + 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im); 
            return result;
        }
        Complex& operator--() 
        {
            double m_re = Re() - 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex operator--(int pepe) 
        {
            Complex result(*this);
            double m_re = Re() - 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return result;
        }
        Complex& operator+=(Complex complex) 
        { 
            double m_re = this->Re() + complex.Re();
            double m_im = this->Im()+ complex.Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex& operator-=(Complex complex) 
        {
            double m_re = this->Re() - complex.Re();
            double m_im = this->Im() - complex.Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex& operator*= (Complex x)
        {
            double m_re = this->Re() * x.Re() - this->Im() * x.Im();           
            double m_im = this->Re() * x.Im() + this->Im() * x.Re();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex& operator/= (Complex x)
        {
            double m_re = (this->Re() * x.Re() + this->Im() * x.Im()) / (x.Re() * x.Re() + x.Im() * x.Im());       
            double m_im = (this->Im() * x.Re() - this->Re() * x.Im()) / (x.Re() * x.Re() + x.Im() * x.Im());
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        friend Complex operator+(Complex lhs, Complex rhs);
        friend Complex operator-(Complex lhs, Complex rhs);
        friend Complex operator*(Complex lhs, Complex rhs);
        friend Complex operator/(Complex lhs, Complex rhs);
        friend Complex operator""i(long double Im);
        friend Complex operator""i(unsigned long long Im);
        friend std::ostream& operator<< (std::ostream& stream, const Complex complex);

    private:
        double m_mod;
        double m_arg;
    };
    Complex operator+(Complex lhs, Complex rhs)
    {
        double re = lhs.m_mod * cos(lhs.m_arg) + rhs.m_mod * cos(rhs.m_arg);
        double im = lhs.m_mod * sin(lhs.m_arg) + rhs.m_mod * sin(rhs.m_arg);
        return Complex(re, im);
    }
    Complex operator-(Complex lhs, Complex rhs)
    {
        double re = lhs.m_mod * cos(lhs.m_arg) - rhs.m_mod * cos(rhs.m_arg);
        double im = lhs.m_mod * sin(lhs.m_arg) - rhs.m_mod * sin(rhs.m_arg);
        return Complex(re, im);
    }
    Complex operator*(Complex lhs, Complex rhs)
    {
        double re = lhs.m_mod * rhs.m_mod * cos(lhs.m_arg + rhs.m_arg);
        double im = lhs.m_mod * rhs.m_mod * sin(lhs.m_arg + rhs.m_arg);
        return Complex(re, im);
    }
    Complex operator/(Complex lhs, Complex rhs)
    {
        double re = (lhs.m_mod * cos(lhs.m_arg) * rhs.m_mod * cos(rhs.m_arg) + lhs.m_mod * sin(lhs.m_arg) * rhs.m_mod * sin(rhs.m_arg)) /
            (rhs.m_mod * rhs.m_mod * cos(rhs.m_arg) * cos(rhs.m_arg) + rhs.m_mod * rhs.m_mod * sin(rhs.m_arg) * sin(rhs.m_arg));
        double im = (lhs.m_mod * sin(lhs.m_arg) * rhs.m_mod * cos(rhs.m_arg) - lhs.m_mod * cos(lhs.m_arg) * rhs.m_mod * sin(rhs.m_arg)) /
            (rhs.m_mod * rhs.m_mod * cos(rhs.m_arg) * cos(rhs.m_arg) + rhs.m_mod * rhs.m_mod * sin(rhs.m_arg) * sin(rhs.m_arg));
        return Complex(re, im);
    }
    Complex operator""i(long double Im) { return Complex(0,Im); }
    Complex operator""i(unsigned long long Im) { return Complex(0,Im); }


    std::ostream& operator<< (std::ostream& stream, const Complex complex)
    {
        if (complex.m_arg >= 0) {
            return stream << complex.m_mod << "+" << complex.m_arg << "i";
        }
        return stream << complex.m_mod << complex.m_arg << "i";
    }

    int FindGreatestCommonDivisor(int a, int b)
    {
        if (a < b)
        {
            int swap = a;
            a = b;
            b = swap;
        }
        int r;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return abs(a);
    }
    int FindLeastCommonMultiple(int x, int y)
    {
        return abs(x * y) / FindGreatestCommonDivisor(x, y);
    }

    export  class Rational
    {

    public:
        void fun()
        {


            int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
            m_nominator = m_nominator / nod;
            m_denominator = m_denominator / nod;
            if (m_denominator < 0)
            {
                m_nominator = -m_nominator;
                m_denominator = -m_denominator;
            }
        }
        Rational() { m_nominator = 0; m_denominator = 1; }
        Rational(int x, int y)
        {
            m_nominator = x;
            m_denominator = y;
            this->fun();
        }
        Rational(int x) { m_nominator = x; m_denominator = 1; }
        int Nominator() const { return m_nominator; } 
        int Denominator() const { return m_denominator; }
        explicit  operator double() {
            return (double)Nominator() / Denominator();
        }
        Rational operator- () { return Rational(-this->m_nominator, this->m_denominator); }
        Rational& operator++ () { this->m_nominator += m_denominator; this->fun(); return *this; }
        Rational operator++ (int x) { Rational star = *this; m_nominator += m_denominator; this->fun(); return star; }
        Rational& operator-- () { this->m_nominator -= m_denominator; this->fun(); return *this; }
        Rational operator-- (int x) { Rational star = *this; m_nominator -= m_denominator; this->fun(); return star; }
        Rational& operator+= (Rational x)
        {
            int no = m_nominator * x.m_denominator + m_denominator * x.m_nominator;
            int de = m_denominator * x.m_denominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        Rational& operator-= (Rational x)
        {
            int no = m_nominator * x.m_denominator - m_denominator * x.m_nominator;
            int de = m_denominator * x.m_denominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        Rational& operator*= (Rational x)
        {
            int no = m_nominator * x.m_nominator;
            int de = m_denominator * x.m_denominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        Rational& operator/= (Rational x)
        {
            int no = m_nominator * x.m_denominator;
            int de = m_denominator * x.m_nominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        friend Rational operator+ (Rational lhs, Rational rhs);
        friend Rational operator- (Rational lhs, Rational rhs);
        friend Rational operator* (Rational lhs, Rational rhs);
        friend Rational operator/ (Rational lhs, Rational rhs);
        friend bool operator== (Rational lhs, Rational rhs);
        friend bool operator<(Rational lhs, Rational rhs);
        friend bool operator>(Rational lhs, Rational rhs);
        friend bool operator<=(Rational lhs, Rational rhs);
        friend bool operator<=(Rational lhs, Rational rhs);

        friend std::ostream& operator<< (std::ostream& os, const Rational& rational);
    private:
        int m_nominator;
        int m_denominator;
    };
    Rational operator+ (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_denominator + lhs.m_denominator * rhs.m_nominator;
        int de = lhs.m_denominator * rhs.m_denominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    Rational operator- (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_denominator - lhs.m_denominator * rhs.m_nominator;
        int de = lhs.m_denominator * rhs.m_denominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    Rational operator* (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_nominator;
        int de = lhs.m_denominator * rhs.m_denominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    Rational operator/ (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_denominator;
        int de = lhs.m_denominator * rhs.m_nominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    bool operator== (Rational lhs, Rational rhs)
    {
        if (lhs.m_nominator == rhs.m_nominator && lhs.m_denominator == rhs.m_denominator)
            return true;
        else
            return false;
    }

    bool operator< (Rational lhs, Rational rhs)
    {
        return (double)lhs < (double)rhs;
    }
    bool operator> (Rational lhs, Rational rhs)
    {
        return (double)lhs > (double)rhs;
    }
    bool operator>= (Rational lhs, Rational rhs)
    {
        return (double)lhs >= (double)rhs;
    }

    bool operator<= (Rational lhs, Rational rhs)
    {
        return (double)lhs <= (double)rhs;
    }


    std::ostream& operator<< (std::ostream& os, const Rational& rational)
    {
        return os << rational.m_nominator << "/" << rational.m_denominator;
    }
    Complex ch(Complex x) {
        return Complex(
            std::cosh(x.Re()) * std::cos(x.Im()) + std::sinh(x.Re()) * std::sin(x.Im())
        );
    }


    Complex f(const Complex& z) {
            Complex a = 2 - 0i;
            return z / a + ch(1 + z);
    }

    Rational ch(Rational x) {
        return std::cosh((double)x);
    }

    Rational f(const Rational& r) {
        Rational a = 2/1;
        return r / a + ch(1 + r);
    }

    double f(double x) {
        double a = 2.0;
        return x / a + cosh(1 + x);
    }


}