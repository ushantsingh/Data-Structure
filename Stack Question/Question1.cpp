// create a stack of max size and convert the stack into circular linked list . taking under consideration that the top most element if the stack must be the last node of the circular linked list

#include<iostream>
#define Max 10
using namespace std;

// ---------------- STACK SECTION ----------------
struct Cstack {
    int data[Max];
    int top;
};

Cstack s1, *p;

void initStack() {
    p = &s1;
    p->top = -1;
}

int Empty() {
    return (p->top == -1);
}

int Full() {
    return (p->top == Max - 1);
}

void Push(int x) {
    if (Full()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    p->top++;
    p->data[p->top] = x;
}

int Pop() {
    if (Empty()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    int y = p->data[p->top];
    p->top--;
    return y;
}

void displayStack() {
    if (Empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "\nStack elements (Top -> Bottom): ";
    for (int i = p->top; i >= 0; i--)
        cout << p->data[i] << " ";
    cout << endl;
}

// ---------------- LINKED LIST SECTION ----------------
struct Node {
    int data;
    Node *next;
};

Node *first = NULL, *temp = NULL, *ttemp = NULL;

void displayCircularList() {
    if (!first) {
        cout << "(Empty Circular List)" << endl;
        return;
    }
    cout << "\nCircular Linked List: ";
    temp = first;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);
    cout << endl;
}

// ---------------- CONVERSION FUNCTION ----------------
void convertStackToCircularList() {
    if (Empty()) {
        cout << "Stack is empty, cannot convert!" << endl;
        return;
    }

    first = new Node;
    first->data = p->data[0];
    first->next = NULL;
    temp = first;

    for (int i = 1; i <= p->top; i++) {
        ttemp = new Node;
        ttemp->data = p->data[i];
        ttemp->next = NULL;
        temp->next = ttemp;
        temp = ttemp;
    }

    temp->next = first;
}

int main() {
    int n, val;

    initStack();
    cout << "Enter number of elements to push into stack (max " << Max << "): ";
    cin >> n;

    if (n > Max) {
        cout << "Error: exceeds max stack size!" << endl;
        return 0;
    }

    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        Push(val);
    }

    displayStack();

    cout << "\nConverting stack into circular linked list..." << endl;
    convertStackToCircularList();
    displayCircularList();

    return 0;
}
