#include<iostream>
#include <cstring>
#include <stack>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;

int Calculate(int o1, int o2, char x){
    switch(x){
        case '+' :
            return o2 + o1;
        case '-' :
            return o2 - o1;
        case '*' :
            return o2 * o1;
        case '/' :
            return o2 / o1;
        case '^' :
            return pow(o2, o1);
        default:
            return -1;
        }
}

void post_Eval(char post[]){
    int op1, op2, R=0;
    int i;
    stack<int> s;

    for (i = 0; i < strlen(post);i++){
        if(isalnum(post[i])){
            s.push(post[i] -'0');
        }
        else{
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            R = Calculate(op1, op2, post[i]);
            s.push(R);
        }
        cout <<"Result : "<<s.top() << endl;
    }
}

int main(){
    char post[50];
    cout << "Enter postfix expression: ";
    cin >> post;
    post_Eval(post);
    return 0;
}