#include <iostream>
using namespace std;

enum AccountType{
    Saving,
    Current,
    Dmat
};

class InsufficientFundsException{
    string message;

public:
    InsufficientFundsException(){

    }

    InsufficientFundsException(string message){
        this->message = message;
    }

    void display(){
        cout<<"Exception : "<<message<<endl;
    }
};

class Account{
    int accno;
    AccountType a1;
    double balance;
public:
    Account(){

    }
    Account(int accno, AccountType a1, double balance){
        this->accno = accno;
        this->balance = balance;
        this->a1 = a1;
    }
    int getaccno(){
        return accno;
    }

    void accept(){
        int type;
        cout<<"Enter Account No ";
        cin>>accno;
        cout<<"Enter account type (0 for Saving, 1 for Current, 2 for Dmat) = ";
        cin>>type;
        a1 = static_cast<AccountType>(type);
        cout<<"Enter Balalance ";
        cin>>balance;
    }
    void display(){
        cout<<"Account no = "<<accno<<endl;
        cout<<"Balance is = "<<balance<<endl;
        cout<<"Account type is = "<<(a1==AccountType::Saving?"Saving":a1==AccountType::Current?"Current":"Dmat")<<endl;

    }

    void deposit(double amount){
        if(amount < 0)
            throw InsufficientFundsException("Amount cannot be less than zero");
        else{
            balance = balance + amount;
            cout<<"New balance is "<<balance<<endl;
         }
    }

    void withdraw(double amount){
        if(amount > balance)
            throw InsufficientFundsException("Insufficient Balance");
        else{
            balance = balance - amount;
            cout<<"New balance is "<<balance<<endl;
        }
    }
};



int searchAccount(Account *a[], int n){

    for(int i=0;i<5;i++){
        if(a[i]->getaccno() == n){
            return i;
        }
    }

    return -1;
}
int menu(){
    int choice;
    cout<<"Enter 1, for Create Account "<<endl;
    cout<<"Enter 2, for display account "<<endl;
    cout<<"Enter 3, for Deposit"<<endl;
    cout<<"Enter 4, for withdraw"<<endl;
    cout<<"Enter your choice "<<endl;
    cin>>choice;
    return choice;

}
int main(){

    Account *a[5];
    int index = -1;
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
         {
            if(index < 5){
                a[++index] = new Account();
                a[index]->accept();
            }else{
                cout<<"Array size is full ....";
            }
         }
            break;
        case 2:
        {
            int acn;
            cout<<"Enter Account no for display account details ";
            cin>>acn;
            int id = searchAccount(a,acn);

            if(id != -1){
                a[id]->display();
            }
            else{
                cout<<"Account Not found"<<endl;
            }
            // for(int i=0;i<index;i++){
            //     if(a[i]->getaccno() == acn){
            //         a[i]->display();
            //     }
            // }
        }
            break;
        case 3:
        {
            int n;
            cout<<"Enter account no for deposite amount ";
            cin>>n;
            int id = searchAccount(a,n);

            if(id != -1){
                try
                {
                    int depAmount;
                    cout<<"Enter Deposite amount";
                    cin>>depAmount;
                    a[id]->deposit(depAmount);
                }
                catch(InsufficientFundsException ex)
                {
                    ex.display();
                }
                
            }else{
                cout<<"Account does not exist";
            }


        }
            break;
        case 4:
        {
            int n;
            cout<<"Enter account no for withdraw amount ";
            cin>>n;
            int id = searchAccount(a,n);

            if(id != -1){
                try
                {
                    int withAmount;
                    cout<<"Enter withdraw amount ";
                    cin>>withAmount;
                    a[id]->withdraw(withAmount);
                }
                catch(InsufficientFundsException ex)
                {
                    ex.display();
                }
                
            }else{
                cout<<"Account does not exist";
            }

        }
            break;
        default:
            cout<<"Please enter correct choice ";
            break;
        }
    }
    
}