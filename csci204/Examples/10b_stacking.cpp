#include <iostream>
using namespace std;

template<class T>
class Stack {
private:
  int size;	// # of elements in the stack
  int top;	// location of the top element
  T *stackPtr;	// pointer to the stack
public:
  Stack(int=10);	// default constructor (stack size=10)
  ~Stack() { delete [] stackPtr;} // destructor
  bool push(const T&);	// push an element onto the stack
  bool pop(T&);		// pop an element off the stack
  void testStack(Stack<T>& theStack, T value, T increment, const char* stackname);

private:
  bool isFull() const {return top == size-1;}
  bool isEmpty() const {return top == -1;}
};

template<class T>
Stack<T>::Stack(int s)
{
  size = s>0?s:10;
  // stack is initially empty
  top = -1;		  
  stackPtr = new T[size]; 
}

template<class T>
bool Stack<T>::push(const T& val)
{
  if(!isFull()) {
    stackPtr[++top] = val;
    return true;
  }
  return false;
}

template<class T>
bool Stack<T>::pop(T& val)
{
  if(!isEmpty()) {
    val = stackPtr[top--];
    return true;
  }
  return false;
}

template<class T>
void testStack(Stack<T>& theStack, T value, T increment, const char* stackName)
{
  cout<<"\nPushing elements onto "<<stackName<<endl;
  while (theStack.push(value)) {
    cout<<value<<" ";
    value +=increment;
  }
  cout<<"\nStack is full, cannot push "<<value;
  cout<<"\n\nPop elements from "<<stackName<<endl;

  while(theStack.pop(value))
    cout<<value<<" ";

  cout<<"\nStack is empty, Cannot pop\n";
}

int main()
{
  Stack<double> doubleStack(5);
  Stack<int> intStack;

  testStack(doubleStack, 1.1, 1.1, "doubleStack");
  testStack(intStack,1,1,"intStack");

  return 0;
}
