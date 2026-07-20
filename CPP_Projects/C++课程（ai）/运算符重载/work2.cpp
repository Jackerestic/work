#include<iostream>

class Complex{
private:
    double real;
    double imag;
public:
    Complex(double r=0.0,double i=0.0):real(r),imag(i){}

    Complex operator+=(const Complex& other){
        real+=other.real;
        imag+=other.imag;
        return *this;
    }
    Complex operator-=(const Complex& other){
        real-=other.real;
        imag-=other.imag;
        return *this;
    }

    Complex& operator--(){
        --real;
        --imag;
        return *this;
    }
    Complex operator--(int){
        Complex temp=*this;
        --(*this);
        return temp;
    }
    Complex& operator++(){
        ++real;
        ++imag;
        return *this;
    }
    Complex operator++(int){
        Complex temp=*this;
        ++(*this);
        return temp;
    }
    friend bool operator<(const Complex& a,const Complex& b){
        double modA=a.real*a.real+a.imag*a.imag;
        double modB=b.real*b.real+b.imag*b.imag;
        return modA<modB;
    }
    friend bool operator>(const Complex& a,const Complex& b){
        double modA=a.real*a.real+a.imag*a.imag;
        double modB=b.real*b.real+b.imag*b.imag;
        return modA>modB;
    }

    friend Complex operator+(const Complex& a,const Complex& b);
    friend Complex operator-(const Complex& a,const Complex& b);
    friend Complex operator*(const Complex& a,const Complex& b);
    friend bool operator==(const Complex& a,const Complex& b);
    friend std::ostream& operator<<(std::ostream& os,const Complex& c);

};

Complex operator+(const Complex& a,const Complex& b){
    return Complex(a.real+b.real,a.imag+b.imag);
}
Complex operator-(const Complex& a,const Complex& b){
    return Complex(a.real-b.real,a.imag-b.imag);
}
Complex operator*(const Complex& a,const Complex& b){
    return Complex(a.real*b.real-a.imag*b.imag,
                   a.real*b.imag+a.imag*b.real);
}
bool operator==(const Complex& a,const Complex& b){
    return a.real==b.real&&a.imag==b.imag;
}
std::ostream& operator<<(std::ostream& os,const Complex& c){
    os<<c.real;
    if(c.imag>=0) os<<"+"<<c.imag<<"i";
    else          os<<"-"<<-c.imag<<"i";
    return os;
}
