// prefix --> infix


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
    char prefix[100];
    int i;
    string str1, str2, str3, str4;
    string t = "";

    init();

    cout << "Enter Prefix Expression " << endl;
    cin >> prefix;

    int n = strlen(prefix);
    reverse(prefix, prefix + n);

    for(i = 0; i < n; i++){

        if(isalnum(prefix[i])){
            string temp = "";
            temp += prefix[i];
            Push(temp);
        }
        else{  
            str1 = Pop();
            str2 = Pop();
            str3 = prefix[i];
            str4 = str1 + str3 + str2;
            Push(str4);
        }
    }

    cout << "Infix Expression : " << Pop() << endl;

    return 0;
}