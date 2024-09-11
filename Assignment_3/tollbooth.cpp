#include <iostream>
using namespace std;

class tollbooth{
    int car;
    double amount;
    int totalcar;

public:
    tollbooth(){
        car = 0;
        amount = 0.0;
        totalcar = 0;
    }
    void paynigCar(){
        totalcar++;
        amount = amount + 0.50;
    }
    void nopayCar(){
        car++;
        totalcar++;
    }
    void printonConsole(){
        cout<<"Total numbers of car are : "<<totalcar<<endl;
        cout<<"Totan Number of car have not paying toll "<<totalcar - car<<endl;
        cout<<"Total Amount is : "<<amount<<endl;
    }
};

int menu(){
    int n;
    cout<<"For freeToll enter 1 "<<endl;
    cout<<"For Not Free Toll enter 2 "<<endl;
    cout<<"For Printing result enter 3 "<<endl;
    cout<<"For exit enter 0 "<<endl;
    cin>>n;
    return n;
}

int main(){

    tollbooth t1;
    int men;
    while ((men=menu()) !=0)
    {
        switch (men)
        {
        case 1:
            t1.nopayCar();
            break;
        case 2:
           t1.paynigCar();
            break;
        case 3:
           t1.printonConsole();
            break;
        
        default:
            cout<<"Wrong Input";
            break;
        }
    }
    return 0;
}