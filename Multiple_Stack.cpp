// Multiple Stack

#include<iostream>
#define Max 6
using namespace std;

struct Mstack{
    int data[Max];
    int topA, topB;
};

Mstack s, *p;

void init(){
    p=&s;
    p->topA = -1;
    p->topB = Max;
}

int EmptyA(){
    if(p->topA==-1){
        return 1;
    }
    else {
        return 0;
    }
}

int EmptyB(){
    if(p->topB==Max){
        return 1;
    }
    else{
        return 0;
    }
}

int Full(){
    if(p->topA+1==p->topB){
        return 1;
    }
    else{
        return 0;
    }
}

int PushA(int x){
    if(Full())
        return 1;
    p->topA++;
    p->data[p->topA] = x;
    cout << x << endl;
}

int PushB(int x){
    if(Full())
        return 1;
    p->topB--;
    p->data[p->topB] = x;
    cout << x << endl;
}

int PopA(){
    int y;
    if (EmptyA())
        return -1;
    y = p->data[p->topA];
    p->topA--;
    cout << y << endl;
}

int PopB(){
    int y;
    if (EmptyB())
        return -1;
    y = p->data[p->topB];
    p->topB++;
    cout << y << endl;
}

int main(){
    init();
    PushA(10);
    PushB(20);
    PushA(30);
    PushB(40);
    PushA(50);
    PushB(60);

    cout << endl;

    PopA();
    PopA();
    PopB();
    PopB();
}