#pragma once
class Stack
{
public:
	int value;
	Stack* next;

	Stack();
	Stack(int value);
	Stack(int value, Stack* next);
};

