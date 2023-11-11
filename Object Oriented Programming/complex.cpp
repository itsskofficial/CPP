//include the libraries and setting standard namespace
#include<iostream>
using namespace std;

//the class complex
class Complex
{
    //declaring the properties parts in private scope
    private:
        int real, imag; //real and imaginary part of complex number

    //declaring the member functions in public scope
    public:
        //constructor with default parameters
        Complex(int r = 0, int i = 0)
        {
            real = r;
            imag = i;
        }

        //friend functions for stream operator overloading
        friend ostream &operator<<(ostream &out, const Complex &obj);
        friend istream &operator>>(istream &in, Complex &obj);
        
        //overloading the arithmetic operators
        Complex operator +(const Complex &obj)
        {
            //seeing from the perspective of first operand
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }

        Complex operator *(const Complex &obj)
        {
            //seeing from the perspective of first operand
            Complex res;
            res.real = real * obj.real;
            res.imag = imag * obj.imag;
            return res;
        }
};

//defining the friend functions
ostream &operator<<(ostream &out, const Complex &obj)
{
        out << obj.real << " + i" << obj.imag;
        return out;
}

istream &operator>>(istream &in, Complex &obj)
{
        cout << "\n\nEnter real part: ";
        in >> obj.real;
        cout << "Enter imaginary part : ";
        in >> obj.imag;
        return in;
}

//driver code
int main()
{
        Complex a, b, c; //creating objects of class complex
        cout << "First complex number";
        cin >> a; //opeator is overloaded
        cout << "\nSecond complex number";
        cin >> b; //opeator is overloaded
        c = a + b; //opeator is overloaded
        cout << "\nAddition of two complex numbers is " << c; //opeator is overloaded
        c = a * b; //opeator is overloaded
        cout << "\nMultipolication of two complex numbers is " << c; //opeator is overloaded
        return 0;
}