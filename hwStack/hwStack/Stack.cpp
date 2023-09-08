#include "Stack.h"
Stack::Stack(){
	value = 0;
	next = nullptr;
}
Stack::Stack(int value) {
	this->value = value;
}
Stack::Stack(int value, Stack* next) {
	this->value = value;
	this->next = next;
}
