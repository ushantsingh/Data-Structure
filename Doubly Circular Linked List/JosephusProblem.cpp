#include<iostream>
# define NULL 0
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

Node *first, *temp, *ttemp, *p, *r;

void createFirstNode(){
    // cout << "Enter the data of the Node: " << endl;
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
    // cout << "Enter data: ";
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

int main(){
    int n, k;
    cout << "Enter the number of people : " << endl;
    cin >> n;
    cout << "Enter the step count : " << endl;
    cin >> k;
    cout << "Enter the Data of Person 1 :" << endl;
    createFirstNode();

    for (int i = 2; i <= n;i++){
        cout << "Enter the Data of Person" << i << ":" << endl;
        addNode();
    }

    cout << "Ring of Person" << endl;
    disp();

    temp = first;
    while(temp->next!=temp){
        for (int count = 1; count < k;count++){
            temp = temp->next;
        }
        cout << "Eliminted : " << temp->data << endl;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if(temp==first) 
            first = temp->next;
            ttemp = temp->next;
            temp->next = temp->prev = NULL;
            delete temp;
            temp = ttemp;
    }
    cout << "The safe Position is : " << temp->data << endl;
    delete temp;
    first = NULL;

    return 0;
}