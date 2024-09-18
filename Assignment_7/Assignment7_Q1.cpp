#include <iostream>
#include <typeinfo>
using namespace std;

class Product{
    int id;
    string title;
    double price;

public:
    Product(){

    }
    Product(int id, string title, double price){
        this->id = id;
        this->price = price;
        this->title = title;
    }
    double getPrice(){
        return price;
    }

    virtual void accept(){
        cout<<"Enter id ";
        cin>>id;
        cout<<"Enter title ";
        cin>>title;
        cout<<"Enter price ";
        cin>>price;
    }
    virtual void display(){
        cout<<"Enter id "<<id<<endl;
        cout<<"Enter title "<<title<<endl;
        cout<<"Enter price "<<price<<endl;
    }

};

class Book: public Product{
    string author;

public:
    Book(){

    }
    Book(int id, string title, double price, string author):Product(id,title,price)
    {
        this->author = author;
    }


    void accept(){
        Product::accept();
        cout<<"Enter author ";
        cin>>author;
    }

    void display(){
        Product::display();
        cout<<"Author is "<<author<<endl;
    }

};

class Tape: public Product{
    string artist;

public:
    Tape(){

    }
    Tape(int id, string title, double price, string artist):Product(id,title,price)
    {
        this->artist = artist;
    }
    void accept(){
        Product::accept();
        cout<<"Enter artist ";
        cin>>artist;
    }

    void display(){
        Product::display();
        cout<<"artist is "<<artist<<endl;
    }
};


int menu(){
    int choice;
    cout<<"For adding Book enter 1"<<endl;
    cout<<"For adding Tape enter 2"<<endl;
    cout<<"For calculate final bill rnter 3"<<endl;
    cin>>choice;
    return choice;
}
int main(){

    Product *p[3];

    int index = 0;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            if(index<3){
            p[index] = new Book;
            p[index]->accept();
            index++;
            }else{
                cout<<"Array is fulll";
            }
            break;
        }
        case 2:
        {
            if(index<3){
            p[index] = new Tape;
            p[index]->accept();
            index++;
            }else{
                cout<<"Array is fulll";
            }
            break;
        }
        case 3:
         {
            int bill = 0;
            for(int i=0;i<index;i++){
                if (typeid(*p[i]) == typeid(Book))
                {
                    
                    bill = bill + (p[i]->getPrice() - p[i]->getPrice()*0.05);
                    
                }
                if (typeid(*p[i]) == typeid(Tape))
                {
                    bill = bill + (p[i]->getPrice() - p[i]->getPrice()*0.10);
                    
                }
                
                
            }

            cout<<"Total bill is "<<bill;
            break;
         }   
            
        default:
            cout<<"Wrong choice";
            break;
        }
    }
    


}