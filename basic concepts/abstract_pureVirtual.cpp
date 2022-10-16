#include <iostream>
#include <string>
using namespace std;
//This class is an abstract class because it has one pure virtual
//funtion and furthur classes derived from it (Abstract class)
class CWH{
    protected:
        string tutorial;
        float time;
    public:
        CWH(string tutorial, float time){
            this->tutorial = tutorial;
            this->time = time;
        }

        // virtual void display(){}
        virtual void display()=0;// pure virtual function
};    

class CWHwords : public CWH{
    int words;
    public:
        //constructors in derived class
        CWHwords(string tutorial, float time, int words) : CWH(tutorial, time){
            this->words = words;
        }

        void display(){
            cout << "Tutorial is " << tutorial << endl;
            cout << "Time is " << time << " minutes" << endl;
            cout << "Rating is " << words << " words" << endl;
        }
};

class CWHrating : public CWH{
    protected:
        float rating;
    public:
        CWHrating(string tutorial, float time, float rating) : CWH(tutorial, time){
            this->rating = rating;
        }
        void display(){
            cout << "Tutorial is " << tutorial << endl;
            cout << "Time is " << time << " minutes" << endl;
            cout << "Words are " << rating << " out of 5" << endl;
        }
};
int main ()
{
    string tutorial = "Python tutorial";
    float time = 19.5;
    int words = 800;
    float rating = 4.7;

    CWHwords obj1(tutorial, time, words);
    CWHrating obj2(tutorial, time, rating);

    CWH* ptr[2];
    ptr[0] = &obj1;
    ptr[1] = &obj2;

    ptr[0]->display();
    ptr[1]->display();
    
    return 0;
}