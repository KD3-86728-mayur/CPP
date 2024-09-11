#include <iostream>
using namespace std;

namespace NStudent{
    class Student{
        int rollNo;
        string name;
        int marks;

    public:
        void accept(int r, string s, int m){
            rollNo = r;
            name = s;
            marks = m;
        }
        void disp(){
            cout<<"Name: "+name<<" RollNo: "+rollNo<<" Marks: "<<marks<<endl;
        }
    };

}

int main(){
    NStudent::Student s1;
    s1.accept(2,"Nayue",22);
    s1.disp();

}