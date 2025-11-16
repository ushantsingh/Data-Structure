// Infix ---> Postfix conversion

#include<iostream>
#define Max 100
using namespace std;
struct Stack{
    int data[Max];
    int top;
};

Stack *p, s;

void init(){
    p = &s;
    p->top = -1;
}

int prioroty(char x){
    if (x == '('){
        return 0;
    }

    if(x=='+'|| x=='-'){
        return 1;
    }
    if(x=='*' || x=='/'){
        return 2;
    }
    if(x=='^'){
        return 3;
    }
}

    int Empty(){
        if(p-> top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int Full(){
        if(p->top ==Max-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    void Push(char x){
        p->top = p->top + 1;
        p->data[p->top] = x;
    }

    char Pop(){
        char x;
        x = p->data[p->top];
        p->top--;
        return x;
    }

    char Top(){
        return (p->data[p->top]);
    }
    
    int main (){
        char x;
        char infix[100];
        char postfix[100];
        int i = 0;
        int j = 0;
    init();
    cout << "Enter Infix Representation : " << endl;
    cin >> infix;
    while (infix[i]!= '\0'){

        if ((infix[i] >= '0' && infix[i] <= '9') ||
            (infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            Push(infix[i]);
        } else if (infix[i] == ')') {
            while (!Empty() && Top() != '(') {
            postfix[j++] = Pop();
            }
            if (!Empty() && Top() == '(') Pop(); // remove '('
        } else { // operator
                                        
            // '^' is right-associative: pop while top has greater precedence
            while (!Empty() && ((prioroty(Top()) > prioroty(infix[i])) ||
               (prioroty(Top()) == prioroty(infix[i]) && infix[i] != '^'))) {
            postfix[j++] = Pop();
            }
            Push(infix[i]);
        }

        i++;

        // if end of input, pop remaining operators and print postfix
        if (infix[i] == '\0') {
            while (!Empty()) {
            postfix[j++] = Pop();
            }
            postfix[j] = '\0';
            cout << "Postfix : " << postfix << endl;
        }
    }
}