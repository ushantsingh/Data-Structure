// // Enter a String and check for non-alphabetic character appearance in that string using stack.

#include<iostream>
#include<cstring>
#define Max 50
using namespace std;

struct Stack{
    char data[Max];
    int top;;
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

int Full(){
    if(p->top==Max-1){
        return 1;
    }
    else {
        return 0;
    }
}

int Push(int x){
    if(Full()){
        cout << "Stack Overflow!" << endl;
        return 0;
    }
    p->top++;
    p->data[p->top] = x;
}

int Pop(){
    if(Empty()){
        cout << "Stack Underflow!" << endl;
        return 0;
    }
    char y = p->data[p->top];
    p->top--;
    return y;
}

int main(){
    init();
    char str[Max];
    cout << "Enter a String :" << endl;
    cin.getline(str,Max);

    int len = strlen(str);

    for (int i = 0; i < len;i++){
        Push(str[i]);
    }

    bool found = false;
    cout << "Checking for non-alphabetic charcters :" << endl;

    while(!Empty()){
        char ch = Pop();
        if (!((ch>='A'&& ch<='Z')||(ch>='a' && ch <='z'))){
            cout << "Non-Alphabetic characters found :" <<ch<< endl;
            found = true;
        }
    }
    if(!found){
        cout << "All Characters are Alphabets " << endl;
    }

    return 0;
}