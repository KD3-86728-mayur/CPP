#include <iostream>
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


int main(){

    Employee *e = new SalesManager;
    e->accept();
    e->display();    

    Employee *e2 = new Salesman;
    e2->accept();
    e2->display();

    Employee *e3 = new Manager;
    e3->accept();
    e3->display();

    Employee *e4 = new Employee;
    e4->accept();
    e4->display();

}