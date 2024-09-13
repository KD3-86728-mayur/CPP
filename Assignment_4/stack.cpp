#include <iostream>
using namespace std;

class stack{
    int size;
    int top;
    int *arr;
    
public:  
    stack(int s=5){
        
        this->arr = new int[s];
        top = -1;


    }
    void push(int p){
        if(top > size){
            cout<<"Stack Overflow";
        }else{
            arr[++top] = p;
        }

    }
    int pop(){
        int n = arr[top];
        top--;
        return n;
    }
    bool isEmpty(){
        if(top=-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top = size-1){
            return true;
        }
        return false;
    }

    void print(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int sizeo(){
        return top+1;
    }

    ~stack(){
        delete[] arr; 
        arr = NULL;
    }
};

int main(){

    stack s1(4);
    s1.push(13);
    s1.push(12);
    s1.push(10);
    s1.push(11);

    s1.print();
    
    cout<<"Pop element : "<<s1.pop()<<endl;
    s1.print();

    cout<<"Size of stack is "<<s1.sizeo()<<endl;




   


}