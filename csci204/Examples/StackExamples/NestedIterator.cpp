//: C16:NestedIterator.cpp
// Nesting an iterator inside the container
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
#include <iostream>
#include <string>
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
  class iterator;
  friend class iterator;
  class iterator {
    IntStack& s;
    int index;
  public:
    iterator(IntStack& is) : s(is), index(0) {}
    // To create the "end sentinel" iterator:
    iterator(IntStack& is, bool) 
      : s(is), index(s.top) {}
    int current() const { return s.stack[index]; }
    int operator++() { // Prefix
      if(index < s.top) cout << "iterator moved out of range";
      return s.stack[++index];
    }
    int operator++(int) { // Postfix
      if(index < s.top)
    	return s.stack[index++];
      else {
        cout<<"iterator moved out of range\n";
	return index;
    }
    }
    // Jump an iterator forward
    iterator& operator+=(int amount) {
      if(index + amount < s.top) {
      	 index += amount;
         return *this;
      } else {
         cout<<"IntStack::iterator::operator+=() ";
         cout<<"tried to move out of bounds";
	 return *this;
      }
      
    }
    // To see if you're at the end:
    bool operator==(const iterator& rv) const {
      return index == rv.index;
    }
    bool operator!=(const iterator& rv) const {
      return index != rv.index;
    }
    friend ostream& 
    operator<<(ostream& os, const iterator& it) {
      return os << it.current();
    }
  };
  iterator begin() { return iterator(*this); }
  // Create the "end sentinel":
  iterator end() { return iterator(*this, true);}
};

int main() {
  IntStack is;
  for(int i = 0; i < 20; i++)
    is.push((i));
  cout << "Traverse the whole IntStack\n";
  IntStack::iterator it = is.begin();
  while(it != is.end())
    cout << it++ << endl;
  cout << "Traverse a portion of the IntStack\n";
  IntStack::iterator 
    start = is.begin(), end = is.begin();
  start += 5, end += 15;
  cout << "start = " << start << endl;
  cout << "end = " << end << endl;
  while(start != end)
    cout << start++ << endl;
} ///:~
