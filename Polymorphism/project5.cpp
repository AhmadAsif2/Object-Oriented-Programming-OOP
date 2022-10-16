//Abstract classes and pure virtual functions
#include <iostream>
#include <vector>
using namespace std;

class Shape {   //Abstract Class
    public:
        virtual void draw() = 0;
        virtual void rotate() = 0;
        virtual ~Shape() { }
};

class open_shape:public Shape { //Abstract class
    //We are not overriding the virtual functions
    public:
        virtual ~open_shape() { }
};

class closed_shape:public Shape {   //Abstract class
    public:
        virtual ~closed_shape() { }
};

class Line:public open_shape {  //Concrete Class
    //We are overrriding the virtual functions
    public:
        virtual void draw() override {
            cout << "Drawing a Line" << endl;
        }
        virtual void rotate() override {
            cout << "Rotating a Line" << endl;
        }
        virtual ~Line() { }
};

class Circle:public closed_shape {  //Concrete class
    public:
        virtual void draw() override {
            cout << "Drawing a Circle" << endl;
        }
        virtual void rotate() override {
            cout << "Rotating a Circle" << endl;
        }
        virtual ~Circle() { }
};

class Square:public closed_shape {  //Concrete class
    public:
        virtual void draw() override {
            cout << "Drawing a Square" << endl;
        }
        virtual void rotate() override {
            cout << "Rotating a Square" << endl;
        }
        virtual ~Square() { }
};

void print(const vector<Shape *> &shapes) {
    cout << "Refreshing" << endl;
    for (const auto p: shapes) {
        p->draw();
        p->rotate();
    }
}

int main() {

    // Shape s;
    // s.draw();//Compiler Error (Because it is abstract class)

    Shape *ptr = new Line(); //Dynamic Binding
    Shape *ptr1 = new Circle();
    Shape *ptr2 = new Square();

    vector<Shape *> shapes {ptr, ptr1, ptr2};
    // for (const auto p:shapes)
    //     p->draw();

    print(shapes);

    delete ptr;
    delete ptr1;
    delete ptr2;

    return 0;
}