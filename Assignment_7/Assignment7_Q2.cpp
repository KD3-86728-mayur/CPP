#include <iostream>
#include <typeinfo>
using namespace std;


class Employee{
    int id;
    double salary;

public:
    Employee(){
        this->id = 1;
        this->salary = 10000;
    }
    Employee(int id, double salary){
        this->id = id;
        this->salary = salary;
    }

    void setId(int id){
        this->id = id;
    }
    void setSalary(double salary){
        this->salary;
    }
    int getId(){
        return id;
    }
    double getSalary(){
        return salary;
    }

    virtual void accept(){
        cout<<"Enter id ";
        cin>>id;
        cout<<"Enter Salary ";
        cin>>salary;
    }

    virtual void display(){
        cout<<"Employee id is "<<id<<endl;
        cout<<"Salary is "<<salary<<endl;
    }
};

class Manager:virtual public Employee{
    double bonus;

protected:
    void acceptManager(){
        cout<<"Enter bonus ";
        cin>>bonus;
    }
    
    void displayManager(){
        cout<<"Bonus is "<<bonus<<endl;
    }

public:
    Manager(){
        this->bonus = 5000;
    }
    Manager(int id, double salary, double bonus):Employee(id,salary)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus){
        this->bonus = bonus;
    }
    double getBonus(){
        return bonus;
    }


    
    void display(){
        Employee::display();
        displayManager();

    }
    void accept(){
        Employee::accept();
        acceptManager();
    }

};

class Salesman :virtual public Employee{
    double commission;

protected:
    void acceptSalesman(){
        cout<<"Enter commission :";
        cin>>commission;
    }
    void displaySalesman(){
        cout<<"commission is : "<<commission<<endl;
    }

public:
    Salesman(){
        this->commission = 5000;
    }
    Salesman(int id, double salary, double commission):Employee(id,salary)
    {
        this->commission = commission;
    }

    double getCommission(){
        return commission;
    }

    void setCommission(double commission){
        this->commission = commission;
    }

    void acceptSalesman(double comnission){
        this->commission = commission;
    }
    void display(){
        Employee::display();
        displaySalesman();
    }
    void accept(){
        Employee::accept();
        acceptSalesman();

    }
};

class SalesManager:public Manager, public Salesman{
public:

    SalesManager(){

    }
    SalesManager(int id, double salary, double bonus, double commission):Manager(id,salary,bonus)
    {
        Salesman::setCommission(commission);
    }

    void display(){
        
        Salesman::display();
        Manager::displayManager();

    }
    void accept(){
        Salesman::accept();
        Manager::acceptManager();

    }
};

int menu(){
    int choice;
    cout<<"Accept Employee Enter 1 "<<endl;
    cout<<"Accept Manager Enter 2 "<<endl;
    cout<<"Accept Salesman Enter 3 "<<endl;
    cout<<"Accept SalesManager Enter 4 "<<endl;
    cout<<"Display the count of all employees with respect to designation 5 "<<endl;
    cout<<"Display all Managers Enter 6 "<<endl;
    cout<<"Display all Salesman Enter 7 "<<endl;
    cout<<"Display all SalesManagers Enter 8 "<<endl;
    cin>>choice;
    return choice;
}


int main(){

    Employee *e[5];
    int index = 0;
    int choi;
    while((choi = menu()) != 0){
        switch (choi)
        {
        case 1:
        {
            if(index<5){
            e[index] = new Employee;
            e[index]->accept(); 
            index++;   
            }
            else
                cout<<"Array size is full....."  ;

            break;
        }
            
        case 2:
         {
            if(index<5){
            e[index] = new Manager;
            e[index]->accept(); 
            index++;   
            }
            else
                cout<<"Array size is full....."  ;
                 
            break;
        }
        case 3:
        {
            if(index<5){
            e[index] = new Salesman;
            e[index]->accept(); 
            index++;   
            }
            else
                cout<<"Array size is full....."  ;
                 
            break;
        }
        case 4:
        {
            if(index<5){
            e[index] = new SalesManager;
            e[index]->accept(); 
            index++;   
            }
            else
                cout<<"Array size is full....."  ;
                 
            break;
        }
        case 5:
        {
            int m = 0;
            int sal = 0;
            int salm = 0;
            for (int i = 0; i < index; i++){
                if (typeid(*e[i]) == typeid(Manager))
                    m++;
                else if (typeid(*e[i]) == typeid(Salesman))
                    sal++;
                else if (typeid(*e[i]) == typeid(SalesManager))
                {
                    salm++;
                }
            }
            
            cout<<"Number of manager is"<<m<<endl;
            cout<<"Number of salesman is"<<sal<<endl;
            cout<<"Number of salesmanager is"<<salm<<endl;
            break;
        }
        case 6:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*e[i]) == typeid(Manager))
                    e[i]->display();
            break;
        }
        case 7:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*e[i]) == typeid(Salesman))
                    e[i]->display();
            break;
        }
        case 8:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*e[i]) == typeid(SalesManager))
                    e[i]->display();
            break;
        }
        default:
            cout<<"Wrong Input ";
            break;
        }
    }

    // Employee *e = new SalesManager;
    // e->accept();
    // e->display();    

    // Employee *e2 = new Salesman;
    // e2->accept();
    // e2->display();

    // Employee *e3 = new Manager;
    // e3->accept();
    // e3->display();

    // Employee *e4 = new Employee;
    // e4->accept();
    // e4->display();

}