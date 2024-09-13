#include <iostream>
using namespace std;

class Time{

    int hr;
    int min;
    int sec;

public:
    Time(){
        this->hr = 10;
        this->min = 50;
        this->sec = 00;
    }
    Time(int h, int m, int s){
        hr = h;
        min = m;
        sec = s;
    }
    
    int gethr(){
        return hr;
    }
    int getmin(){
        return min;
    }
    int getsec(){
        return sec;
    }



    void sethr(int hrs){
        this->hr = hrs;
    }

    void setmin(int mn){
        this->min = mn;
    }

    void setsec(int sc){
        this->sec = sc;
    }
    void accept(){
        cout<<"Enter time ";
        cin>>this->hr>>this->min>>this->sec;
    }

    void printTime(){
        cout<<this->hr<<":"<<this->min<<":"<<this->sec<<endl;
    }


};

int main(){

    Time **ptr = new Time*[5];

    // ptr[0]->accept();
    // ptr[0]->printTime();

    for (int i = 0; i < 5; i++)
    {
        ptr[0] = new Time();
        
    }
    ptr[0]->printTime();

    for (int i = 0; i < 5; i++)
    {
        delete ptr[i];
        ptr[i] = NULL; 
        /* code */
    }
    delete[] ptr;
    ptr=NULL;
    
    

}