#include <iostream>

using namespace std;

class Stack
{
private:
  int *arr;
  int capacity;
  int top;

  void resize();

public:
  Stack(int initialSize = 5);
  ~Stack();
  void push(int d);
  int pop();
  bool isEmpty();
  int getCapacity();
  int peak();
  int size();
};

void Stack::resize()
{
  this->capacity *= 2;
  int *newArr = new int[this->capacity];
  for (int i = 0; i <= this->top; i++)
  {
    newArr[i] = this->arr[i];
  }

  delete[] arr;
  arr = newArr;
}

Stack::Stack(int initialSize)
{
  this->capacity = initialSize;
  this->arr = new int[this->capacity];
  this->top = -1;
}

Stack::~Stack()
{
  delete[] this->arr;
}

void Stack::push(int d)
{
  if (this->top == this->capacity - 1)
  {
    this->resize();
  }
  this->arr[++this->top] = d;
}

int Stack::pop()
{
  if (this->isEmpty())
  {
    cout << "Stack is Empty" << endl;
    return -1;
  }
  return this->arr[this->top--];
}

bool Stack::isEmpty()
{
  return this->top == -1;
}

int Stack::getCapacity()
{
  return this->capacity;
}

int Stack::peak()
{
  if (this->isEmpty())
  {
    return -1;
  }
  return this->arr[this->top];
}

int Stack::size()
{
  return this->top + 1;
}
