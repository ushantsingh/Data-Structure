// a singly linked list contains mixed data of albhabet and numbers. convert tihs singly linked list to form two seoarate stacks in which one stack should contain alll the albhabet and another stack contain all the number . 

#include<iostream>
#define Max 10
using namespace std;

struct Stack {
    char data[Max];
    int top;
};

Stack *p1, *p2, s1, s2;

void initAlphabet() {
    p1 = &s1;
    p1->top = -1;
}

void initNumber() {
    p2 = &s2;
    p2->top = -1;
}

int Empty(Stack *p) {
    return (p->top == -1);
}

int Full(Stack *p) {
    return (p->top == Max - 1);
}

void Push(Stack *p, char x) {
    if (Full(p)) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    p->top++;
    p->data[p->top] = x;
}

char Pop(Stack *p) {
    if (Empty(p)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    char y = p->data[p->top];
    p->top--;
    return y;
}

// ---------- Linked List ----------
struct Node {
    char data;
    Node *next;
};

Node *first, *temp, *ttemp;

void createFirst(char val) {
    first = new Node;
    first->data = val;
    first->next = NULL;
}

void addNode(char val) {
    temp = first;
    while (temp->next != NULL)
        temp = temp->next;
    ttemp = new Node;
    ttemp->data = val;
    ttemp->next = NULL;
    temp->next = ttemp;
}

void dispList() {
    cout << "\nLinked List elements: ";
    temp = first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------- Conversion Function ----------
void convertToStack() {
    temp = first;
    while (temp != NULL) {
        char ch = temp->data;
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            Push(p1, ch);     // Alphabet stack
        else if (ch >= '0' && ch <= '9')
            Push(p2, ch);     // Number stack
        temp = temp->next;
    }
}

void dispStack(Stack *p, string name) {
    if (Empty(p)) {
        cout << name << " is empty!" << endl;
        return;
    }
    cout << "\n" << name << " (Top -> Bottom): ";
    for (int i = p->top; i >= 0; i--)
        cout << p->data[i] << " ";
    cout << endl;
}

int main() {
    int n;
    char val;

    cout << "Enter number of elements in linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    cout << "Enter " << n << " elements (alphabets or digits): " << endl;
    cin >> val;
    createFirst(val);
    for (int i = 2; i <= n; i++) {
        cin >> val;
        addNode(val);
    }

    dispList();

    initAlphabet();
    initNumber();

    cout << "\nConverting linked list into two stacks..." << endl;
    convertToStack();

    dispStack(p1, "Alphabet Stack");
    dispStack(p2, "Number Stack");

    return 0;
}
