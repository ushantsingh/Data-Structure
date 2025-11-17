// Infix --> Prefix conversion

#include<iostream>
#include<string>
#define Max 100
using namespace std;

struct Stack{
    string data[Max];
    int top;
};

Stack *p1, *p2, s1, s2;

void Operator(){
    p1 = &s1;
    p1->top = -1;
}

void Operand(){
    p2 = &s2;
    p2->top = -1;
}

int prioroty(char x){
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int Empty(Stack *p){
    return (p->top == -1);
}

void Push(Stack *p, string x){
    p->data[++p->top] = x;
}

string Pop(Stack *p){
    return p->data[p->top--];
}

string Top(Stack *p){
    return p->data[p->top];
}

int main(){
    char infix[100];
    int i = 0;
    string str1, str2, str3, str4, str5;

    Operator(); 
    Operand();  

    cout << "Enter Infix Representation : ";
    cin >> infix;

    while(infix[i] != '\0'){

        if (isalnum(infix[i])) {
            string temp = "";
            temp += infix[i];
            Push(p2, temp);
        }

        else if(infix[i] == '('){
            string t = "(";
            Push(p1, t);
        }

        // ')'
        else if(infix[i] == ')'){
            while(!Empty(p1) && Top(p1) != "("){
                str1 = Pop(p2);     
                str2 = Pop(p2);     
                str3 = Pop(p1);     

                str4 = str3 + str2 + str1; 
                Push(p2, str4);
            }
            Pop(p1);
        }

        else {
            while(!Empty(p1) &&
                  (prioroty(Top(p1)[0]) > prioroty(infix[i]) ||
                   (prioroty(Top(p1)[0]) == prioroty(infix[i]) && infix[i] != '^')) )
            {
                str1 = Pop(p2);
                str2 = Pop(p2);
                str3 = Pop(p1);

                str4 = str3 + str2 + str1;
                Push(p2, str4);
            }

            string t = "";
            t += infix[i];
            Push(p1, t);
        }

        i++;
    }

    while(!Empty(p1)){
        str1 = Pop(p2);
        str2 = Pop(p2);
        str3 = Pop(p1);

        str4 = str3 + str2 + str1;
        Push(p2, str4);
    }

    cout << "Prefix Expression : " << Top(p2) << endl;

    return 0;
}