#include <iostream>
using namespace std;

struct Node {
    string data;
    Node *next;
};

Node *first = NULL, *temp = NULL, *ttemp = NULL;

void createFirst(string val) {
    first = new Node;
    first->data = val;
    first->next = NULL;
}

void addNode(string val) {
    temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    ttemp = new Node;
    ttemp->data = val;
    ttemp->next = NULL;
    temp->next = ttemp;
}

void disp() {
    temp = first;
    cout << "Linked list elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int isPalindrome = 1;

    // Create the first node
    createFirst(string(1, str[0]));

    // Add remaining characters
    for (int i = 1; i < str.length(); i++) {
        addNode(string(1, str[i]));
    }
    // Display the linked list
    disp();

    for(int i=0;i<str.length()-i-1;i++)
    {
        if(str[i] != str[str.length()-i-1])
        {    
            isPalindrome=0;
            break;
        }
    }
        
        if(isPalindrome)
        {
            cout << "It is Palindrome" << endl;
        }
        else
        {
            cout << "It is not Palindrome" << endl;
        }


    return 0;
}
