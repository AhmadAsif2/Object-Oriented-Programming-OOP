/*
	Polymorphism
		Complile Time
			->Static Binding/ Early Binding
		Run Time
			->Dynamically Binding/ Late Binding

*/
#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
	void say_hello() {
		cout << "Hello I am Base Class Object" << endl;
	}
};

class Derived :public Base {
public:
	void say_hello() {
		cout << "Hello I am Derived Class Object" << endl;
	}
};

void greetings(Base& obj) {
	cout << "Greetings: ";
	obj.say_hello();
}

int main() {

	Base b;
	b.say_hello();

	Derived d;
	d.say_hello();


	/*
		Static Binding always called Base class Function 
	*/
	greetings(b);
	greetings(d);

	//Static Binding always called Base Class Function
	Base* ptr = new Derived();
	ptr->say_hello();

	//Static Bindng in smart pointers called Base Class Function
	unique_ptr<Base> ptr1 = make_unique<Derived>();
	ptr1->say_hello();

	delete ptr;

	cin.get();
	return 0;
}