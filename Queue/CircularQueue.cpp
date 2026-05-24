#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

class CQueue
{
  Node *front;
  Node *rear;

public:
  CQueue();
  CQueue(int data);

  void enqueue(int data);
  void dequeue();
  void Traversal();
  bool isEmpty();
};

CQueue::CQueue() : front(nullptr), rear(nullptr) {}

CQueue::CQueue(int data) : CQueue()
{
  this->enqueue(data);
}

void CQueue::enqueue(int data)
{
  Node *new_node = new Node{data, this->front};
  if (this->front == nullptr)
  {
    this->rear = new_node;
    this->front = new_node;
    this->rear->next = this->front;
    return;
  }

  this->rear->next = new_node;
  this->rear = new_node;
  this->rear->next = this->front;
}

void CQueue::dequeue()
{
  if (this->isEmpty())
  {
    cout << "List already empty" << endl;
    return;
  }

  Node *temp = this->front;
  if (this->front == this->rear)
  {
    this->front = nullptr;
    this->rear = nullptr;
  }
  else
  {
    this->front = this->front->next;
    this->rear->next = this->front;
  }

  temp->next = nullptr;
  delete temp;
}

void CQueue::Traversal()
{
  cout << "Traversal: ";
  Node *ptr = this->front;
  do
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  } while (ptr != this->front);

  cout << endl;
}

bool CQueue::isEmpty()
{
  return this->front == nullptr;
}
