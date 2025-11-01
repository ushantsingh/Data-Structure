// singly circular linked list

#include<iostream>
#define NULL 0
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *first, *temp, *ttemp, *p, *q;

void createFirstNode(){
    cout << "Enter the data of the Node" << endl;
    first = new Node;
    cin >> first->data;
    first->next = first;
}

void addNode(){
    temp = first;
    while(temp->next!=first){
        temp = temp->next;
    }
    ttemp = new Node;
    cin >> ttemp->data;
    ttemp->next = first;
    temp->next = ttemp;
}

void disp(){
    cout<<"\n"<<endl;
    temp = first;
    do{
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != first);
}

void addBeforeFirstNode(){
    cout << "Adding node before first node" << endl;
    temp = first;
    while(temp->next!=first){
        temp = temp->next;
    }
    p = new Node;
    cin >> p->data;
    p->next = first;
    temp->next = p;
    first = p;
}

void delFirstNode(){
    cout << "Deleating first node" << endl;
    temp = first;
    while(temp->next !=first){
        temp = temp->next;
    }
    ttemp = first->next;
    temp->next = ttemp;
    first->next = NULL;
    delete first;
    first = ttemp;
}

void delLastNode(){
    cout << "Deleating last node" << endl;
    temp = first;
    while(temp->next!=first){
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = first;
    temp->next = NULL;
    delete temp;
    temp = ttemp;
}

void swapFirstAndSecondNode(){
    temp = first;
    p = first->next;
    ttemp = p->next;
    while(temp->next!=first){
        temp = temp->next;
    }
    first->next = ttemp;
    p->next = first;
    temp->next = p;
    first = p;
}

void swapLastAndFirstNode(){
    temp = first;
    p = first->next;
    while(temp->next !=first){
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = first;
    temp->next = p;
    first->next = temp;
    first = temp;
}

void swapLastAndSecondLastNode(){
    temp = first;
    while(temp->next->next!=first){
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    p->next = temp;
    temp->next = first;
    temp = p;
}

int main(){
    createFirstNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    disp();

    // cout << endl;
    // addBeforeFirstNode();
    // disp();
    // cout << endl;
    // delFirstNode();
    // disp();
    // cout << endl;
    // delLastNode();
    // disp();
    // cout << endl;
    // swapFirstAndSecondNode();
    // disp();
    // cout << endl;
    // swapLastAndFirstNode();
    // disp();
    cout << endl;
    swapLastAndSecondLastNode();
    disp();
}