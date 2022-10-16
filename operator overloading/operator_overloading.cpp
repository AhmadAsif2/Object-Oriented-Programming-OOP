#include <iostream>
using namespace std;

class Calculator {
    protected:
        double a, b, c;
    public:

        Calculator()
            : a(0), b(0), c(0){
            }
        
        Calculator(double a, double b, double c) {
            this->a =a;
            this->b = b;
            this->c = c;
        }

        Calculator operator+(const Calculator &obj);
        Calculator operator-(const Calculator &obj);

         void display() {
            cout << "After Multiplying and Divide values"
                << "(" << a << ", " << b << ", " << c << ")" << endl;
        }
        
};

Calculator Calculator::operator+(const Calculator &obj) {
    Calculator source;
    source.a = a + obj.a;
    source.b  = b + obj.b;
    source.c = c + obj.c;
    return source;
}

Calculator Calculator::operator-(const Calculator &obj) {
    Calculator source;
    source.a = a - obj.a;
    source.b = b - obj.b;
    source.c = c - obj.c;
    return source;
}

class ExtendedCalculator: public Calculator {
    public:
        // double a1, a2, a3
        using Calculator::Calculator;
        ExtendedCalculator()
            : Calculator{} {
               
            }
        ExtendedCalculator(double a, double b, double c)
            : Calculator(a, b, c) {
                this->a = a;
                this->b = b;
                this->c = c;
        }
        ExtendedCalculator operator*(const ExtendedCalculator &obj) {
            ExtendedCalculator source;
            source.a = a * obj.a;
            source.b = b * obj.b;
            source.c = c * obj.c;
            return source;
        }
        ExtendedCalculator operator/(const ExtendedCalculator &obj) {
            ExtendedCalculator source;
            source.a = a / obj.a;
            source.b = b / obj.b;
            source.c = c / obj.c;
            return source;
        }
        void display() {
            cout << "After Multiplying and Divide values"
                << "(" << a << ", " << b << ", " << c << ")" << endl;
        }
};

int main() {

    Calculator obj(2, 3, 5);
    Calculator obj1(3, 4, 5);
    Calculator result = obj+ obj1;
    result.display();

    // ExtendedCalculator obj(2, 3, 5);
    // ExtendedCalculator obj1(3, 4, 5);
    // ExtendedCalculator result = obj * obj1;
    // result.display();
    

    return 0;
}