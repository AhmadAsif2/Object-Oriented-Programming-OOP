#include <iostream>
using namespace std;

class Student {
    protected:
        int roll_no;
    public:
        void setRoll(int roll) {
            roll_no = roll;
        }

        void print () {
            cout << "Your roll no is " << roll_no << endl;
        }

};

class Test : virtual public Student {
    protected:
        int maths, physics;
    public:
        void set_marks(float m1, float m2) {

            maths = m1;
            physics = m2;
        }
        void get_marks() {

            cout << "Your marks are: " << endl 
                 << "maths " << maths << endl
                 << "physics " << physics << endl;
        }
};

class Sports : virtual public Student {
    protected:
        int score;
    public:
        void set_score(int sc) {

            score = sc; 
        }

        void get_score() {

            cout << "Your score is " << score << endl;
        }

};

class Result : public Test, public Sports {
    public:
        void show() {

            print();
            get_marks();
            get_score();
            
        }
};
int main () {

    Result obj;
    obj.setRoll(2);
    obj.set_marks(93, 99);
    obj.set_score(10);
    obj.show();

    return 0;
}