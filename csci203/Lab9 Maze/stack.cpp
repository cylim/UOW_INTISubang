#include "stack.h"

stack::stack( )	// default constructor, which 
{ 				// creates a new Stack and
	top = -1;	// initializes top to -1
}	
		
//returns true if Stack is empty, otherwise returns false
bool stack::isEmpty( )
{
	if (top < 0)
		return true;    
	else
		return false;
}

bool stack::push(stackItem newItem)
{
    if (top >= MAX_STACK - 1)  
		return false;
    top++;
    items[top] = newItem;
    return true;
}

bool stack::pop (stackItem &data)
{
    if (isEmpty( ))
 		return false;
    data = items[top];
    top--;
    return true;
}

bool stack::peek (stackItem &data)
{
    if (isEmpty( )) 
		return  false;
    data = items[top];
    return true;
}

