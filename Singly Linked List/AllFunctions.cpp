// Singly linked list

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
    while (temp != NULL)
    {
        cout << temp->data<< endl;
        temp = temp->next; 
    }
}

void addAfterFirst(int x){
    p = new Node;
    p->data = x;
    p->next = first->next;
    first->next = p;
}

void addBeforeGivenData(int x, int y){
    temp = first; 
    while(temp->data!=x){
        ttemp = temp;
        temp = temp->next;
    }
    p = new Node;
    p->data = y;
    p->next = ttemp->next;
    ttemp->next = p;
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

void delFirstNode(){
    temp = first;
    first = temp->next;
    temp->next = NULL;
    delete temp;
}

void delLastNode(){
    temp = first;
    while(temp->next!=NULL){
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = NULL;
    delete temp;
}

void delAfterGivenData(int x){
    temp = first;
    while(temp->data!=x){
        temp = temp->next;
    }
    ttemp = temp->next;
    p = ttemp->next;
    temp->next = p;
    ttemp->next = NULL;
    delete ttemp;
}

void delBeforeGivenData(int x){
    temp = first;
    while(temp->next->data!=x){
        ttemp = temp;
        temp=temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    temp->next = NULL;
    delete temp;
}

void swapFirstAndSecond(){
    temp = first->next;
    ttemp = temp->next;
    temp->next = first;
    first->next = ttemp;
    first = temp;
}

void swapLastAndSecondLast(){
    temp = first;
    while (temp->next->next !=NULL){
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    p->next = temp;
    temp->next = NULL;
}

void swapFirstAndLast(){
    temp = first;
    p = first->next;
    while(temp->next != NULL){
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = first;
    first->next = NULL;
    temp->next = p;
    first = temp;
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
    // cout << endl;
    // addBeforeGivenData(40, 80);
    // disp();
    // cout << "" << endl;
    // addBeforeFirstNode(90);
    // disp();
    // cout << "" << endl;
    // reverseLinkedList();
    // disp();
    // cout << endl;
    // delFirstNode();
    // disp();
    // cout << endl;
    // delAfterGivenData(40);
    // disp();
    // cout << endl;
    // delBeforeGivenData(40);
    // disp();
    // cout << endl;
    // delLastNode();
    // disp();
    // cout << endl;
    // swapFirstAndSecond();
    // disp();
    // cout << endl;
    // swapLastAndSecondLast();
    // disp();
    cout << endl;
    swapFirstAndLast();
    disp();
}