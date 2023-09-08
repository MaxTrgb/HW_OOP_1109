#include <iostream>
#include <ctime>
#include "Node.h"
using namespace std;

// Function to add a new node with a character value to the end of the linked list
void putNodeToTail(Node*& head, char value) {
    Node* n = new Node(value);

    // If the linked list is empty, set the new node as the head
    if (head == nullptr) {
        head = n;
        return;
    }

    // Traverse to the end of the list and add the new node
    Node* tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = n;
}

// Function to display the values in the linked list
void display(Node* head) {
    Node* tmp = head;

    while (tmp != nullptr) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

// Function to check if the linked list is empty
bool check(Node* head) {
    return head == nullptr;
}

// Function to add a character to the end of the linked list
void addToTail(Node*& head, char value) {
    Node* tmp = head;

    // Traverse to the end of the list and add the new node
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new Node(value);
}

// Function to remove and return the first character from the linked list
char takeFromHead(Node*& head) {
    char tmp = head->value;

    // Remove the first node and free memory
    Node* temp = head;
    head = head->next;
    delete temp;

    return tmp;
}

// Function to search for a character in the linked list
bool search(Node* head, char value) {
    Node* tmp = head;

    while (tmp != nullptr) {
        if (tmp->value == value) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Function to clear the linked list and release memory
void clear(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to split the linked list into English and other characters
void createNewLines(Node*& head, Node*& english, Node*& other) {
    Node* tmp = head;

    while (tmp != nullptr) {
        if ((tmp->value >= 'A' && tmp->value <= 'Z') || (tmp->value >= 'a' && tmp->value <= 'z')) {
            putNodeToTail(english, tmp->value);
        }
        else {
            putNodeToTail(other, tmp->value);
        }
        tmp = tmp->next;
    }
}

int main() {
    srand(time(nullptr));
    Node* node = nullptr;
    Node* english = nullptr;
    Node* other = nullptr;

    // Generate and add random characters to the linked list
    for (int i = 0; i < 5; i++) {
        putNodeToTail(node, char(rand() % (126 - 33) + 33));
    }

    cout << "Original Queue: ";
    display(node);
    cout << endl;

    if (check(node)) {
        cout << "\nList is empty" << endl;
    }
    else {
        cout << "\nList is not empty" << endl;
    }

    char value;
    cout << "\nEnter value to add: ";
    cin >> value;

    // Add a character to the end of the linked list
    addToTail(node, value);
    display(node);
    cout << endl;

    cout << "\nFirst element: ";
    cout << takeFromHead(node) << endl;
    display(node);
    cout << endl;

    char value1;
    cout << "\nEnter value to search: ";
    cin >> value1;

    // Search for a character in the linked list
    if (search(node, value1)) {
        cout << "Element is present" << endl;
    }
    else {
        cout << "Element is not present" << endl;
    }
    cout << "Original Queue: ";
    display(node); cout << endl;

    // Split the linked list into English and other characters
    createNewLines(node, english, other);

    cout << "English Queue: ";
    display(english);
    cout << endl;

    cout << "Other Queue: ";
    display(other);
    cout << endl;

     //Clear the linked list
     clear(node);
     cout << "\nOriginal Queue after clear: ";
     display(node);
     cout << endl;


    return 0;
}
