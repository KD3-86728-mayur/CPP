#include <iostream>
using namespace std;

class address{
    string building;
    string street;
    string city;
    int pin;

    
public:
    address(){
        building = "ABC";
        street = "XYZ";
        city = "PQR";
        pin = 0;
    }

    void accept(){

        cout<<"Enter Building, street, city and pin : ";
        cin>>building>>street>>city>>pin;
    }

    void setbuilding(string b){
        building = b;
    }
    void setstreet(string s){
        street = s;
    }
    void setCity(string c){
        city = c;
    }
    void setPin(int p){
        pin = p;
    }

    string getBuilding(){
        return building;
    }

    string getStreet(){
        return street;
    }

    string getCity(){
        return city;
    }

    int getPin(){
        return pin;
    }

};
int main(){

    address a1;
    address a2;
    address a2;
    // a1.setbuilding("Shree Ram");
    // a1.setstreet("Mangaon");
    // a1.setCity("Raigad");
    // a1.setPin(100);
    a1.accept();

    cout<<"Building name is "<<a1.getBuilding()<<endl;
    cout<<"Street name is "<<a1.getStreet()<<endl;
    cout<<"City name is "<<a1.getCity()<<endl;
    cout<<"Pin Code is "<<a1.getPin()<<endl;

    return 0;

}
