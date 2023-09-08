#include "Node.h"

// Default constructor for Node: initializes value to 0 and next to nullptr
Node::Node() {
    value = 0;
    next = nullptr;
}

// Constructor for Node with a character value: initializes value to the provided value and next to nullptr
Node::Node(char value) {
    this->value = value;
    next = nullptr;
}

// Constructor for Node with a character value and a pointer to the next Node
Node::Node(char value, Node* next) {
    this->value = value;
    this->next = next;
}
