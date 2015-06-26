#include "Stack.h"

Stack::Stack()	// default constructor, which 
{ 				// creates a new Stack and
	top = -1;	// initializes top to -1
}

//returns true if Stack is empty, otherwise returns false
bool Stack::isEmpty()
{
	if (top < 0)
		return true;
	else
		return false;
}

bool Stack::push(int newItem)
{
	if (top >= MAX_STACK - 1)
		return false;
	top++;
	items[top] = newItem;
	return true;
}

bool Stack::pop(int &data)
{
	if (isEmpty())
		return false;
	data = items[top];
	top--;
	return true;
}

bool Stack::peek(int &data)
{
	if (isEmpty())
		return  false;
	data = items[top];
	return true;
}

