#include <iostream>
using namespace std;
#include "Stack.h"

// Function to push a value onto the stack
void push(Stack*& head, int value) {
    Stack* n = new Stack(value);

    if (head == nullptr) {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

// Function to display the elements of the stack
void display(Stack*& head) {
    Stack* tmp = new Stack();

    tmp = head;

    while (tmp != nullptr) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

// Function to compare two stacks and create a new stack with common and negative values
void compare(Stack*& head1, Stack*& head2) {
    Stack* newStack = nullptr;

    while (head1 != nullptr && head2 != nullptr) {

        if (head1->value == head2->value) {
            // If values are equal, push them onto the new stack
            push(newStack, head1->value);
        }
        else
        {
            if (head1->value < 0) {
                // If head1 value is negative, push it onto the new stack
                push(newStack, head1->value);
            }
            if (head2->value < 0) {
                // If head2 value is negative, push it onto the new stack
                push(newStack, head2->value);
            }
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Display the new stack containing common and negative values
    display(newStack);
}

int main() {
    Stack* head1 = nullptr;
    Stack* head2 = nullptr;

    // Push values onto the stacks (for the same stacks)
    //for (int i = 1; i < 6; i++)
    //{
    //	push(head1, i);
    //}
    //for (int i = 1; i < 6; i++)
    //{
    //	push(head2, i);
    //}

    // Push values onto the stacks (for the different stacks)
    push(head1, 1);
    push(head1, 2);
    push(head1, 3);
    push(head1, 4);
    push(head1, -5);

    push(head2, 6);
    push(head2, 7);
    push(head2, -8);
    push(head2, 9);
    push(head2, 11);
    push(head2, 13);

    // Display the original stacks
    cout << "Stack 1: ";
    display(head1);
    cout << endl;

    cout << "Stack 2: ";
    display(head2);
    cout << endl;

    // Compare the stacks and display the result
    cout << "Reversed stack or stack with negative numbers: " << endl;
    compare(head1, head2);

    return 0;
}

