// Create Linked List in Sorted Order

#include<iostream>
#define NULL 0
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *first, *temp, *ttemp, *p, *q;

void init(){
    first = temp = ttemp = NULL;
}

void createFirstNode(){
    first = new Node;
    cin >> first->data;
    first->next = NULL;
}

void addNode(){
    temp = first;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    ttemp = new Node;
    cin >> ttemp->data;
    ttemp->next = NULL;
    temp->next = ttemp;
}

void disp(){
    temp=first;
    while(temp!=NULL){
        cout << temp->data<<endl;
        temp = temp->next;
    }
}

void shortLinkedList(){
    for (p = first; p != NULL;p=p->next){
        for (q = p->next; q != NULL;q=q->next){
            if(p->data>q->data){
                int temporary = p->data;
                p->data = q->data;
                q->data = temporary;
            }
        }
    }
}

int main(){
    init();
    int n;
    cout << "Enter the number of Nodes : " << endl;
    cin >> n;
    cout << "Enter the data for node 1 :" << endl;
    createFirstNode();

    for (int i = 2; i <= n;i++){
        cout << "Enter the data of node " << i <<": "<< endl;
        addNode();
    }

    cout << "Original Linked List " << endl;
    disp();

    cout << "Sorted Linked List : " << endl;
    shortLinkedList();
    disp();

    return 0;
}
