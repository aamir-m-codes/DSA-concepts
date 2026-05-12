#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

class Stack
{
public:
    Node *top;

    Stack();
    Stack(int d);
    void push(int d);
    int pop();
    bool isEmpty();
    int peak();
};

Stack::Stack()
{
    this->top = nullptr;
}

Stack::Stack(int d)
{
    this->top = nullptr;
    this->push(d);
}

void Stack::push(int data)
{
    Node *n = new Node{data, nullptr};
    if (n == nullptr)
        cout << "Stack Overflow" << endl;
    else
    {
        n->next = this->top;
        top = n;
    }
}

int Stack::pop()
{
    if (this->isEmpty())
    {
        cout << "Stack UnderFlow" << endl;
        return -1;
    }
    Node *temp = this->top;
    this->top = this->top->next;
    int data = temp->data;
    delete temp;
    return data;
}


bool Stack::isEmpty()
{
    return (this->top == nullptr) ? 1 : 0;
}

int Stack::peak(){
    if(this->isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return this->top->data;
}