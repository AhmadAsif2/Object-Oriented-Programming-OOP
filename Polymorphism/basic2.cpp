/*
* Virtual Functions (Dynamically Binding/ Late Binding)
* Run Time Polymorphism
* All Virtual functions have virtual Destructors
*/
#include <iostream>
#include <vector>
using namespace std;

class Account {
public:
	virtual void withdraw(double amount) {
		cout << "Account::Withdraw called" << endl;
	}

	virtual ~Account() {
		cout << "Account::Destructor" << endl;
	}
};

class Savings :public Account {
public:
	virtual void withdraw(double amount) {
		cout << "Savings::Withdraw called" << endl;
	}

	virtual ~Savings() {
		cout << "Savings::Destructor" << endl;
	}
};

class Checking :public Account {
public:
	virtual void withdraw(double amount) {
		cout << "Checking::Withdraw" << endl;
	}

	virtual ~Checking() {
		cout << "Checking::Destructor" << endl;
	}
};

class Test :public Account {
public:
	virtual void withdraw(double amount) {
		cout << "Test::Withdraw" << endl;
	}

	virtual ~Test() {
		cout << "Test::Destructor" << endl;
	}
};

int main() {
		
	Account* p1 = new Account();
	Account* p2 = new Savings();
	Account* p3 = new Checking();
	Account* p4 = new Test();

	//Late Binding Dynamically (Run Time Polymorphism)
	p1->withdraw(1000);
	p2->withdraw(1000);
	p3->withdraw(1000);
	p4->withdraw(1000);

	//Using Arrays for late Binding
	cout << "\n====Array=====" << endl;
	Account* array[] = {p1, p2, p3, p4};
	array[0] = p4;
	for (int i = 0; i <= 3; ++i) 
		array[i]->withdraw(1000);

	//Using Vectors for late Binding
	cout << "\n====Vectors====" << endl;
	vector<Account*>accounts = { p1, p2, p3, p4 };
	accounts.push_back(p4);
	accounts.push_back(p4);
	accounts.push_back(p4);
	for (auto acc_ptr : accounts)
		acc_ptr->withdraw(1000);

	cout << "\n====Freeing Memory====" << endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}