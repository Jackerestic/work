#include<iostream>

class Complex{
private:
    double real;
    double imag;
public:
    Complex(double r=0.0,double i=0.0)
        :real(r),imag(i){}
    
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
    if(c.imag>=0)os<<"+"<<c.imag<<"i";
    else         os<<"-"<<-c.imag<<"i";
    return os;
}

int main() {
    Complex c1(3, 4), c2(1, -2);
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";
    std::cout << "c1 + c2 = " << c1 + c2 << "\n";
    std::cout << "c1 - c2 = " << c1 - c2 << "\n";
    std::cout << "c1 * c2 = " << c1 * c2 << "\n";
    std::cout << "c1 == c2? " << (c1 == c2 ? "true" : "false") << "\n";
    return 0;
}