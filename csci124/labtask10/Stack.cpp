#include <iostream>
#include "Stack.h"
using namespace std;

stack::stack()
{
    head = NULL;
    ssize = 0;
}

bool stack::isempty()
{
    if( ssize == 0 )
        return true;
    else
        return false;
}

int stack::size()
{
    return ssize;
}

bool stack::push(const T& obj)
{
    if( isempty() )
    {
        head = new node;
        if( head == NULL )
            return false;

        head->data = obj;
        head->next = NULL;
        ssize ++;
        return true;
    }
    else
    {
        nodeptr tmp = new node;
        if( tmp == NULL )
            return false;

        tmp->next = head;
        tmp->data = obj;
        head = tmp;
        ssize ++;
        return true;
    }
}

bool stack::pop(T& obj)
{
    if( isempty() )
        return false;

    else
    {
        nodeptr tmp = head;
        obj = head->data;
        head = head->next;
        delete tmp;
        ssize --;
        return true;
    }
}
