#include <iostream>
#include <string.h>

using namespace std;

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double r = 0, double i = 0) 
        : real(r), imag(i){};//생성자
        Complex operator+(const Complex other){
            Complex temp;
            temp.real = this->real + other.real;//this생략 가능
            temp.real = real + other.real;
            temp.imag = imag + other.imag;
            
            return temp;
        }
        friend ostream& operator<<(ostream& out, const Complex& obj);
};

ostream& operator<<(ostream& out, const Complex& obj){
    out << obj.real;
    if(obj.imag >0)
        out << "+" << obj.imag<< "i";
    else
        out << "-" << -obj.imag<< "i";
}
int main(){
    Complex r1(2.3 , 5.6);//기본생성자 묵시적 생성됨
    Complex r2(3.2 , 1.3);

    Complex result = r1 + r2;
    cout << r1 << r2 << result << endl;
    return 0;
}