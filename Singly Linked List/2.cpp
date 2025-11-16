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
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void addAfterFirst(int x){
    p = new Node;
    p->data = x;
    p->next = first->next;
    first->next = p;
}

void addAfterGivenNode(int x, int y){
    temp = first;
    while(temp->data!=x){
        temp = temp->next;
    }
    ttemp = new Node;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}

void addBeforeFirstNode(int x){
    p = new Node;
    p->data = x;
    p->next = first;
    first=p;
}

void reverseLinkedList(){
    previous = NULL;
    curr = first;
    nextt = NULL;
    while(curr!=NULL){
        nextt = curr->next;
        curr->next = previous;
        previous = curr;
        curr = nextt;
    }
    first = previous ;
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
    // cout << "" << endl;
    // addAfterFirst(70);
    // disp();
    // cout << "" << endl;
    // addAfterGivenNode(30, 80);
    // disp();
    // cout << "" << endl;
    // addBeforeFirstNode(90);
    // disp();
    cout << "" << endl;
    reverseLinkedList();
    disp();
}