#include<iostream>
#define NULL 0
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

Node *first, *temp, *ttemp, *p,*q;

void createFirstNode(){
    cout << "Enter the Data of Nodes" << endl;
    first = new Node;
    cin >> first->data;
    first->next = NULL;
    first->prev = NULL;
}

void addNode(){
    temp = first;
    while(temp->next != NULL){
        temp = temp->next;
    }
    ttemp = new Node;
    cin >> ttemp->data;
    ttemp->next = NULL;
    ttemp->prev = temp;
    temp->next = ttemp;
}

void disp(){
    temp = first;
    cout<<"\n"<<endl;
    while(temp !=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void addBeforeFirst(){
    cout << "Enter the Data to add Before Node" << endl;
    p = new Node;
    cin >> p->data;
    p->next = first;
    p->prev = NULL;
    first->prev = p;
    first = p;
}

void addBeforeGivenData(int x){
    temp = first;
    while(temp->data !=x){
        ttemp = temp;
        temp = temp->next;
    }
    cout << "Enter the Data to add before " << endl;
    p = new Node;
    cin >> p->data;
    p->next = temp;
    p->prev = ttemp;
    ttemp->next = p;
    temp->prev = p;
}

void addAfterGivenData(int x){
    cout << "Enter the Data to add after the node" << endl;
    temp = first;
    while(temp->data !=x){
        temp = temp->next;
    }
    ttemp = temp->next;
    p = new Node;
    cin >> p->data;
    p->next = ttemp;
    p->prev = temp;
    temp->next = p;
    ttemp->prev = p;
}

void swapFirstAndSecondNode(){
    cout << "Swapping Linked List" << endl;
    temp = first->next;
    ttemp = temp->next;
    first->next = ttemp;
    first->prev = temp;
    ttemp->prev = first;
    temp->next = first;
    temp->prev = NULL;
    first = temp;
}

void swapLastAndFirst(){
    cout << "Swapping last and First" << endl;
    temp = first;
    p = first->next;
    while(temp->next!=NULL){
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = first;
    first->prev = ttemp;
    first->next = NULL;
    temp->next = p;
    temp->prev = NULL;
    p->prev = temp;
    first = temp;
}

void swapLastAndSecondLast(){
    cout << "Swapping last and second last" << endl;
    temp = first;
    while(temp->next->next != NULL){
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    p->prev = ttemp;
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
    temp = p;
}

void swapAnyTwoNode(int x, int y){
    cout << "Swapping " << x << " & " << y << endl;
    temp = first;
    p = first->next;
    while(temp->data != y){
        ttemp = temp;
        temp = temp->next;
    }
    q = temp->next;
    p->next = temp;
    temp->prev = p;
    temp->next = ttemp;
    ttemp->prev = temp;
    ttemp->next = q;
    q->prev = ttemp;
    ttemp = temp;
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
    // addBeforeFirst();
    // // disp();
    // cout << endl;
    // addBeforeGivenData(40);
    // disp();
    // cout << endl;
    // addAfterGivenData(40);
    // disp();
    // cout << endl;
    // swapFirstAndSecondNode();
    // disp();
    // cout << endl;
    // swapLastAndFirst();
    // disp();
    // cout << endl;
    // swapLastAndSecondLast();
    // disp();
    cout << endl;
    swapAnyTwoNode(30,40);
    disp();
}