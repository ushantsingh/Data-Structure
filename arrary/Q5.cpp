// a linked list contain all natural number from 1 to 10 .  split the linked list in two separate list show that one list contains all the even numbers and another list contain all the odd numbers 

#include<iostream>
#define NULL 0
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *first, *temp, *ttemp, *p, *q, *r;
Node *oddFirst=NULL, *evenFirst=NULL, *oddTail=NULL,*evenTail = NULL;

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
    while(temp->next!=NULL){
        temp = temp->next;
    }
    ttemp = new Node;
    ttemp->data = val;
    ttemp->next = NULL;
    temp->next = ttemp;
}

void disp(Node *start){
    temp = start;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void splitOddEven(){
    temp = first;
    while(temp!=NULL){
        Node *nextNode = temp->next; // Store next before breaking link.
        temp->next = NULL; // Detach the node from original list.

        if(temp->data%2==0){
            if(evenFirst==NULL){
            evenFirst = temp;
            evenTail = temp;
            }
            else{
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else{
            if(oddFirst==NULL){
                oddFirst = temp;
                oddTail = temp;
            }
            else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = nextNode;
    }
    cout << "Odd numbers list:" << endl;
    disp(oddFirst);

    cout << "Even numbers list:" << endl;
    disp(evenFirst);
}

int main(){
    init();
    createFirst(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);
    addNode(9);
    addNode(10);
    disp(first);

    cout << "" << endl;

    splitOddEven();
}