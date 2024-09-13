#include <iostream>
using namespace std;

class Date{
    int day;
    int month;
    int year;

public:
    void setDay(int day){
        this->day = day;
    }
    void setMonth(int month){
        this->month = month;
    }
    void setYear(int year){
        this->year = year;
    }

  

    void printdate(){
        cout<<"Birthdate is "<<day<<"-"<<month<<"-"<<year<<endl;
    }

};

class Person{
    string name;
    string address;
    Date birthdate;

public:
    Person(string name, string addr, int date, int month, int year){
        this->name = name;
        this->address = addr;
        birthdate.setDay(10);
        birthdate.setMonth(10);
        birthdate.setYear(2002);
    }

    void display(){
        cout<<"Name of person is "<<name<<endl;
        cout<<"Address is "<<address<<endl;
        birthdate.printdate();
        
    }

};
int main(){
    Person p1("Mayur","Mangaon",10, 20,2002);
    p1.display();

}