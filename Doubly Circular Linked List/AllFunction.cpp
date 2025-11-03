// // Doubly circular linked list


#include<iostream>
#define NULL 0
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

Node *first, *temp, *ttemp, *p, *q;

void createFirstNode(){
    cout << "Enter the data of the Node: ";
    first = new Node;
    cin >> first->data;
    first->next = first;
    first->prev = first;
}

void addNode(){
    temp = first;
    while(temp->next != first){
        temp = temp->next;
    }
    ttemp = new Node;
    cout << "Enter data: ";
    cin >> ttemp->data;
    ttemp->next = first;
    ttemp->prev = temp;
    temp->next = ttemp;
    first->prev = ttemp;
}

void disp(){
    cout << "\nList elements:\n";
    temp = first;
    if (!first) return;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != first);
    cout << endl;
}

void swapFirstSecondNode(){
    cout << "\nSwapping first and second node\n";
    Node* last = first->prev;
    Node* second = first->next;
    Node* third = second->next;

    last->next = second;
    second->prev = last;

    second->next = first;
    first->prev = second;

    first->next = third;
    third->prev = first;

    first = second;
}

void addBeforeFirstNode(){
    cout << "Adding a Node before first Node " <<endl;
    temp = first->prev;
    ttemp = new Node;
    cin >> ttemp->data;
    ttemp->next = first;
    first->prev = temp;
    temp->next = ttemp;
    ttemp->prev = temp;
    ttemp->prev = temp;
    first = ttemp;
}


void delFirstNode(){
    cout << "Deleating First Node" << endl;
    temp = first->prev;
    ttemp = first;
    p = first->next;
    temp->next = p;
    p->prev = temp;
    first = first->next;
    ttemp->next = ttemp->prev = NULL;
    delete ttemp;
}

void delLastNode(){
    temp = first->prev;
    ttemp = first->next;
    p = temp->prev;
    p->next = first;
    first->prev = p;
    temp->next = temp->prev = NULL;
    delete temp;
}

void swapLastSecondLast(){
    cout << "Swapping last and second last node" << endl;
    temp = first->prev;
    ttemp = temp->prev;
    p = ttemp->prev;
    p->next = temp;
    temp->next = ttemp;
    temp->prev = p;
    ttemp->next = first;
    first->prev = ttemp;
    ttemp = temp;
}

void swapFirstAndLastNode(){
    temp=first->prev;
    ttemp = first->next;
    p = temp->prev;
    p->next = first;
    first->prev = p;
    first->next = temp;
    temp->next = ttemp;
    temp->prev = first;
    temp->prev = first;
    ttemp->prev = temp;
    first = temp;
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

    // swapFirstSecondNode();
    // disp();
    // cout << endl;
    // delFirstNode();
    // disp();
    // cout << endl;
    // delLastNode();
    // disp();
    // cout << endl;
    // swapLastSecondLast();
    // disp();
    cout << endl;
    swapFirstAndLastNode();
    disp();

    return 0;
}
