// Reverse a number using array implementation of stack

#include<iostream>
#define Max 10
using namespace std;

struct Stack{
    int data[Max];
    int top;
};

Stack *p, s1;

void init(){
    p = &s1;
    p->top = -1;
}

int Empty(){
    if(p->top==-1){
        return 1;
    }
    else {
        return 0;
    }
} 

int  Full(){
    if(p->top==Max-1){
        return 1;
    }
    else {
        return 0;
    }
}

void Push(int x){
    if(Full()){
        cout << "Stack Overflow!" << endl;
        return;
    }
    p->top++;
    p->data[p->top] = x;
    // cout << x << endl;
}

int Pop(){
    int y;
    if(Empty()){
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    y = p->data[p->top];
    p->top--;
    return y;
}

int main(){
    int num, digit;
    cout << "Enter the Number :" << endl;
    cin >> num;

    init();

    while(num>0){
        digit = num % 10;
        Push(digit);
        num /= 10;
    }

    cout << "Reversed Number :" << endl;
    while(!Empty()){
        cout << Pop();
    }
}