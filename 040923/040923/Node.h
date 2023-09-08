#pragma once

class Node {
public:
    // Public member variables
    char value;     
    Node* next;     

    // Constructors
    Node();                       // Default constructor
    Node(char value);              // Constructor with a character value
    Node(char value, Node* next);  // Constructor with a character value and a pointer to the next node
};
