//: C16:IterIntStack.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
#include <iostream>
using namespace std;

class IntStack {
  enum { ssize = 100 };
  int stack[ssize];
  int top;
public:
  IntStack() : top(0) {}
  void push(int i) {
    if(top < ssize)
    	stack[top++] = i;
    else
        cout<<"Stack is full\n";
  }
  int pop() {
    if(top > 0)
        return stack[--top];
	else {
		cout<<"Too many pops\n";
		return -1;
	}
  }
  friend class IntStackIter;
};

// An iterator is like a "smart" pointer:
class IntStackIter {
  IntStack& s;
  int index;
public:
  IntStackIter(IntStack& is) : s(is), index(0) {}
  int operator++() { // Prefix
    if(index < s.top) 
    	return s.stack[++index];
    else {
    	cout<<"iterator moved out of range\n";
	return index;
    }
    
  }
  int operator++(int) { // Postfix
    if(index < s.top)
    	return s.stack[index++];
    else {
        cout<<"iterator moved out of range\n";
	return index;
    }
    
  }
};

int main() {
  IntStack is;
  for(int i = 0; i < 20; i++)
    is.push(i);
  // Traverse with an iterator:
  IntStackIter it(is);
  for(int j = 0; j < 20; j++)
    cout << it++ << endl;
} ///:~
