#include <iostream>
using namespace std;
class date{
    int day;
    int month;
    int year;

public:
    void intidate(){
        day = 1;
        month = 1;
        year = 1900;
        cout<<"Date is : "<<day<<"-"<<month<<"-"<<year<<endl;

    }
    void acceptDateFromConsole(){
        cout<<"Enter Date :"<<endl;
        cin>>day>>month>>year;
    }
    void printDateOnConsole(){
        cout<<"Date is : "<<day<<"-"<<month<<"-"<<year<<endl;
    }
    bool idLeapYear(){

        if(( (year % 4) == 0 && year % 100 != 0) || (year % 400 == 0)){
            return true;
        } 
        return false;
        
    }
};

int choice(){
    int n;
    cout<<"Enter 0 for exit "<<endl;
    cout<<"Enter 1 for init date "<<endl;
    cout<<"Enter 2 for Accept date  "<<endl;
    cout<<"Enter 3 for print date "<<endl;
    cout<<"Enter 4 for checking leap year "<<endl;

    cin>>n;
    return n;
}

int main(){

    date d1;
    int nu;
    bool check;
    while((nu=choice()) != 0){
        switch (nu)
        {
        case 0:
            break;
        case 1:
            d1.intidate();
            break;
        case 2:
            d1.acceptDateFromConsole();
            break;
        case 3:
            d1.printDateOnConsole();
            break;
        case 4:

            check = d1.idLeapYear();
            if(check){
                cout<<"Leap Year"<<endl;
            }else{
                cout<<"not Leap Year"<<endl;
            }
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
        

    }

    return 0;

}