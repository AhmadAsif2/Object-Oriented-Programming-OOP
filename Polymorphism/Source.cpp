#include <iostream>
using namespace std;

class Base {
public:
	virtual void say_hello() const  {
		cout << "Hello I am base class object" << endl;
	}
	virtual ~Base(){}
};

class Derived :public Base {
public:
	//Function Overriding
	virtual void say_hello()const override final {
		cout << "Hello I am Derived class object" << endl;
	}
	//Destructor
	virtual ~Derived(){}
};


int main() {

	Base* p1 = new Base();
	p1->say_hello();

	Derived* p3 = new Derived();
	p3->say_hello();

	Base* p2 = new Derived();
	p2->say_hello();

	return 0;
}