// Postfix --> Infix

#include<iostream>
#include<string>
#include<algorithm>
#define Max 100
using namespace std;

struct Stack{
    string data[Max];
    int top;
};

Stack *p, s1;

void init(){
    p = &s1;
    p->top = -1;
}

int prioroty(char x){
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int Empty(){
    return (p->top == -1);
}

void Push(string x){
    p->data[++p->top] = x;
}

string Pop(){
    return p->data[p->top--];
}

string Top(){
    return p->data[p->top];
}

int main(){
    char postfix[100];
    int i = 0;
    string str1, str2, str3, str4, str5;
    string t = "";

    init();

    cout << "Enter the Postfix Expression : " << endl;
    cin >> postfix;

    int n = strlen(postfix);

    for (i = 0; i < n;i++){
        if(isalnum(postfix[i])){
            string temp = "";
            temp += postfix[i];
            Push(temp);
        }
        else{
            str1 = Pop();
            str2 = Pop();
            str3 = postfix[i];
            str4 = str2 + str3 + str1;
            Push(str4);
        }
    }
    cout << "Infix Expression : " << Pop() << endl;
    
    return 0;
}