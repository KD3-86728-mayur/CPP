#include <iostream>
using namespace std;

class box{
    int length;
    int breadth;
    int height;

public:
    box(){
        length = 10;
        breadth = 12;
        height = 15;
    }
    box(int n){
        length = n;
        breadth = n;
        height = n;
    }
    box(int l, int b, int h){
        length = l;
        breadth = b;
        height = h;
    }
    void volumedef1(){
         int vol1 = height*breadth*length; 
         cout<<"Volume is "<<vol1<<endl;  
    }
    void volumedef2(){
         int vol2 = height*breadth*length;   
         cout<<"Volume is "<<vol2<<endl;  
    }
    void volumedef3(){
         int vol3 = height*breadth*length;  
         cout<<"Volume is "<<vol3<<endl;   
    }

};

int menu(){
    int n;
    cout<<"For default value enter 1 "<<endl;
    cout<<"For One Parameter enter 2 "<<endl;
    cout<<"For Three Parameter enter 3 "<<endl;
    
    cout<<"For exit enter 0 "<<endl;
    cin>>n;
    return n;
}


int main(){
    int men;
    while((men=menu()) != 0){
        switch (men)
        {
        case 1:
            {
                box b1;
                b1.volumedef1();
            }
            break;
        case 2:
            {
                int n1;
                cout<<"Enter One parameter: ";
                cin>>n1;
                box b2(n1);
                b2.volumedef2();
            }
            break;
        case 3:
            {
                int n1,n2,n3;
                cout<<"Enter three parameter: ";
                cin>>n1>>n2>>n3;
                box b3(n1,n2,n3);
                b3.volumedef3();
            }
            break;  
        default:
            cout<<"Wrong Input"<<endl;
            break;
        }
    }
}
