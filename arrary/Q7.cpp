#include<iostream>
#define NULL 0
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node *first, *temp, *ttemp, *p, *q, *r,*curr,*previous,*nextt;

void init(){
    first = temp = ttemp = NULL;
}

void createFirst(int val){
    first = new Node;
    first->data = val;
    first->next = NULL;
}

void addNode(int val){
    temp = first;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    ttemp = new Node;
    ttemp->data = val;
    ttemp->next = NULL;

    temp->next = ttemp;
}

void disp(){
    temp = first;
    int i = 1;
    while (temp != NULL)
    {
        cout << "Node"<<i<<" -> "<< temp->data<< endl;
        temp = temp->next;
        i++;
    }
}

void addAfterFirst(int x){
    p = new Node;
    p->data = x;
    p->next = first->next;
    first->next = p;
}

int main(){
    init();
    createFirst(10);
    addNode(20);
    addNode(30);
    addNode(40);
    addNode(50);
    addNode(60);
    disp();
}