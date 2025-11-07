
// Check whether a given string is a Palindrome or not using stack 

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
    else{
        return 0;
    }
}

int Full(){
    if(p->top==Max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int Push(int x){
    if(Full()) {
        cout << "Stack Overflow!" << endl;
        return 0;
    }
    p->top++;
    p->data[p->top] = x;
    // cout << x;
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
    init();
    char str[Max];
    cout << "Enter a String :" << endl;
    cin >> str;

    int len = strlen(str);
    bool isPalindrome = true;

    // Pushing all element 
    for (int i = 0; i < len;i++){
        Push(str[i]);
    }

    for (int i = 0; i < len;i++){
         if(str[i]!=str[len-i-1]){
             isPalindrome = false;
             break;
         }
    }
    if(isPalindrome){
        cout << "The string is Palindrome!" << endl;
    }
    else{
        cout << "The String is not Palindrome !" << endl;
    }
}
