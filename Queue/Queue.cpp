#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

class Queue
{
  Node *front;
  Node *rear;

public:
  Queue();
  Queue(int data);

  void enqueue(int data);
  void dequeue();
  void Traversal();
  bool isEmpty();
};

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::Queue(int data) : Queue()
{
  this->enqueue(data);
}

void Queue::enqueue(int data)
{
  Node *new_node = new Node{data, nullptr};
  if (this->isEmpty())
  {
    this->front = new_node;
    this->rear = new_node;
  }
  else
  {
    this->rear->next = new_node;
    this->rear = new_node;
  }
}

void Queue::dequeue()
{
  if (isEmpty())
  {
    cout << "Queue is Empty" << endl;
    return;
  }

  Node *temp = this->front;
  this->front = this->front->next;

  if (this->isEmpty())
  {
    this->rear = nullptr;
  }
  
  temp->next = nullptr;
  delete temp;
}

void Queue::Traversal()
{
  cout << "Printing: " << endl;
  Node *ptr = this->front;
  while (ptr != nullptr)
  {
    std::cout << "Value: " << ptr->data << std::endl;
    ptr = ptr->next;
  }
}

bool Queue::isEmpty()
{
  return this->front == nullptr;
}
