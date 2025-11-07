// create two stack of size 5 ,5 and merge them in third stack of 10 size in alternate order .

#include<iostream>
#define Max1 5
#define Max2 5
#define Max3 10
using namespace std;

struct Stacks{
    int data[Max3];
    int top;
};

Stacks *p, s1,s2,s3;

void init(){
    p = &s1;
    p = &s2;
    p = &s3;
    s1.top = -1;
    s2.top = -1;
    s3.top = -1;
}

int Empty(){
    if(p->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int Full(int size){
    if(p->top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int Push(int x,int size){
    if(Full(size)){
        cout<<"Stack Overflow!"<<endl;
        return 0;
    }
    p->top++;
    p->data[p->top] = x;
}

int Pop(){
    int y;
    if (Empty())
    {
        cout << "Stack Underflow!" << endl;
        return 0;
    }
    y = p->data[p->top];
    p->top--;
    return y;
}

int main(){
    init();

    cout << "Enter the 5 Element in Stack 1 :" << endl;
    p = &s1;
    for (int i = 0; i < Max1;i++){
        int x;
        cin >> x;
        Push(x, Max1);
    }

    cout << "Enter the 5 Element in Stack 2 :" << endl;
    p = &s2;
    for (int i = 0; i < Max2;i++){
        int x;
        cin >> x;
        Push(x, Max2);
    }

    while(s1.top!=-1 || s2.top!=-1){
        if(s2.top!=-1){
            p = &s2;
            int val2 = Pop();
            p = &s3;
            Push(val2, Max3);
        }
        if(s1.top!=-1){
            p = &s1;
            int val1 = Pop();
            p = &s3;
            Push(val1, Max3);
        }
    }

    cout << "Merged Stack :" << endl;
    p = &s3;
    while(!Empty()){
        cout << Pop() << " ";
    }
    cout << endl;
}