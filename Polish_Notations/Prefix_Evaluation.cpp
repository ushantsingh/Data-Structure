#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
#include<stack>      
#include<algorithm>  
#include<cstring>  
using namespace std;

int Calculate(int o1,int o2, char x){
    switch(x){
        case '+' :
            return o1 + o2;
        case '-' :
            return o1 - o2;
        case '*' :
            return o1 * o2;
        case '/' :
            return o1 / o2;
        case '^' :
        return pow(o1, o2);
        default :
            return -1;
        }
}

void prefix_Eval(char pre[]){
    int op1, op2, R = 0;
    int i;
    stack<int> s;

    reverse(pre,pre+strlen(pre));
    for (int i = 0; i < strlen(pre); i++)
    {
        if(isalnum(pre[i])){
            s.push(pre[i] - '0');
        }
        else{
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            R = Calculate(op1, op2, pre[i]);
            s.push(R);
        }
        cout << "Result : " << s.top() << endl;
    }
}

int main(){
    char pre[50];
    cout << "Enter Prefix Expression : " << endl;
    cin >> pre;
    prefix_Eval(pre);
    return 0;
}