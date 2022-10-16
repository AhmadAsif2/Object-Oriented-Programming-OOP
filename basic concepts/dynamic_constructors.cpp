#include<iostream>
#include<cmath>
using namespace std;
class SimpleCalculator{
    protected:
    int a,b;
    public:
    void set1(int n1, int n2){
        a=n1;
        b=n2;
    }
    void display1(){
        cout<<"The sum of two numbers is "<<a+b<<endl;
        cout<<"The difference of two numbers is "<<a-b<<endl;
        cout<<"The multiplication of two numbers is "<<a*b<<endl;
        cout<<"The division of two numbers is "<<int(a/b)<<endl;
    }
};
class ScientificCalculator{
    protected:
    int a,b;
    public:
    void set2(int no1, int no2){
        a=no1;
        b=no2;
    }
    void display2(){
        cout<<"The sine of two numbers are "<<sin(a)<<"  "<<sin(b)<<endl;
        cout<<"The cosine of two numbers are "<<cos(a)<<"  "<<cos(b)<<endl;
        cout<<"The tan of two numbers are "<<tan(a)<<"  "<<tan(b)<<endl;
        cout<<"The logarithms of two numbers are "<<log(a)<<"  "<<log(b)<<endl;
    }
};

class HybridCalculator:public SimpleCalculator, public ScientificCalculator{
    public:
    void show(){
        display1();
        display2();
        cout<<"The calculations are done "<<endl;
    }

};
int main(){
    HybridCalculator h;
    int num1, num2;
    cout<<"Enter two numbers "<<endl;
    cin>>num1>>num2;
    h.set1(num1,num2);
    h.set2(num1, num2);
    h.show();
}