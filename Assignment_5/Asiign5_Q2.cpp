#include <iostream>
using namespace std;

class student{
    string name;
    string gender;
    const int rollno;
    int arr[3];
    static int generate;
public:

    student():rollno(++generate)
    {
        name = "Mayur";
        gender = "Male";
        arr[0] = 100;
        arr[1] = 100;
        arr[2] = 100;
    }

    student(string name, string gender, int arr[]):rollno(++generate)
    {
        this->name = name;
        this->gender = gender;
        for (int i = 0; i < 3; i++)
        {
            this->arr[i] = arr[i];
        }
        
    }

    int getID(){
        return rollno;
    }

    void accept(){
        cout<<"Enter Name ";
        cin>>name;
        cout<<"Enter gender ";
        cin>>gender;
        cout<<"Enter marks ";
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }

    }
    void print(){
        cout<<"ID "<<rollno<<endl;
        cout<<"Name of student is "<<name<<endl;
        cout<<"Gender is "<<gender<<endl;
        cout<<"Marks of three subjects "<<arr[0]<<", "<<arr[1]<<", "<<arr[2]<<endl;
        cout<<"Percentages "<<(arr[0]+arr[1]+arr[2])/3<<endl;
    }
    int search(){

    }
};

int student::generate = 0;

bool search(int n,student *arr[5]){
    for(int i=0;i<5;i++){
        if(arr[i]->getID() == n){
            return true;
        }
    }
    return false;
}

int menu(){
    int n;
    cout<<"For accept value enter 1 "<<endl;
    cout<<"For print enter 2 "<<endl;
    cout<<"For searching enter 3 "<<endl;
    cout<<"For exit enter 0 "<<endl;
    cin>>n;
    return n;
}

int main()
{
    // student **arr = new student *

    student *arr[5];

    for(int i=0;i<2;i++){
        arr[i] = new student();
    }

        int count = 0;
        int cho;
        while ((cho = menu()) != 0 )
        {
            switch (cho)
            {
            case 1:
                arr[count++]->accept();
                break;
            case 2:
            {
                for (int i = 0; i < count; i++)
                {
                    arr[i]->print();
                }
                
            }
                
                break;
            case 3:
            {
                int num=0;
                cout<<"Enter the student id for searching ";
                cin>>num;
                cout<<search(num,arr);
                break;
            }
            default:
                cout<<"Wrong input";
                break;
            }
        }
        
        
        
    


}