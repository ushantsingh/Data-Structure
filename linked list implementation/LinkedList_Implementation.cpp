#include<iostream>
// #define NULL 0
using namespace std;

struct LStack{
    int data;
    LStack *next;
};

LStack *top, *temp, *ttemp;

void init(){
    top = temp = NULL;
}

void Push(int x){
    temp = new LStack;
    if(temp==NULL)
        return;
    temp->data = x;
    temp->next = top;
    top = temp;
    cout << x << endl;
}

int Pop(int x){
    
    if(top==NULL){
        return -1;
    }
        x = top->data;
        temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        return x;
}

int main(){
    init();
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Push(60);

    cout << endl;

    cout<<Pop(20)<<endl;
    cout<<Pop(50)<<endl;
}