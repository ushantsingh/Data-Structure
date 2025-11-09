#include<iostream>
#define Max 5
using namespace std;

struct Stacks{
    int data[Max];
    int top;
};

Stacks *p, s1;

void init (){
    p = &s1;
    p->top = -1;
}

int Empty(){
    if (p->top==-1){
        return 1;
    }
    else {
        return 0;
    }
}

int Full(){
    if(p->top==Max-1){
        return 1;
    }
    else {
        return 0;
    }
}

void Push(int x){
    if(Full()){
        cout << "Stack Overflow" << endl;
        return ;
    }
    p->top++;
    p->data[p->top] = x;
    cout << x << endl;
}

int Pop( ){
    int y;
    if (Empty()){
        cout << "Stack Unnderflow!" << endl;
        return -1;
    }
    y = p->data[p->top];
    p->top--;
    return y;
}

int main(){
    init();
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);

    cout << endl;
    cout << Pop() << endl;
    cout<<Pop()<<endl;
}