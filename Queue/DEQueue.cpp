#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *pre;
  struct Node *next;
} Node;

class DEQueue
{
  Node *front;
  Node *rear;

public:
  DEQueue();
  DEQueue(int data);
  ~DEQueue();

  void enqueueR(int data);
  void enqueueF(int data);
  void dequeueF();
  void dequeueR();

  void Traversal();
  bool isEmpty();
};

DEQueue::DEQueue() : front(nullptr), rear(nullptr) {}

DEQueue::DEQueue(int data) : DEQueue()
{
  this->enqueueR(data);
}

DEQueue::~DEQueue()
{
  Node *temp;

  while (this->front)
  {
    temp = this->front;
    this->front = this->front->next;
    temp->pre = nullptr;
    temp->next = nullptr;
    delete temp;
  }

  this->front = nullptr;
  this->rear = nullptr;
}

void DEQueue::enqueueR(int data)
{
  Node *new_node = new Node{data, this->rear, nullptr};

  if (this->isEmpty())
  {
    this->front = this->rear = new_node;
    return;
  }

  this->rear->next = new_node;
  this->rear = new_node;
}

void DEQueue::enqueueF(int data)
{
  Node *new_node = new Node{data, nullptr, this->front};

  if (this->isEmpty())
  {
    this->front = this->rear = new_node;
    return;
  }

  this->front->pre = new_node;
  this->front = new_node;
}

void DEQueue::dequeueF()
{
  if (this->isEmpty())
  {
    cout << "Queue already empty" << endl;
    return;
  }

  Node *temp = this->front;
  if (this->front == this->rear)
  {
    this->front = this->rear = nullptr;
  }
  else
  {
    this->front = this->front->next;
    this->front->pre = nullptr;
  }

  temp->next = nullptr;

  delete temp;
}

void DEQueue::dequeueR()
{
  if (this->isEmpty())
  {
    cout << "Queue already empty" << endl;
    return;
  }

  Node *temp = this->rear;
  if (this->front == this->rear)
  {
    this->front = this->rear = nullptr;
  }
  else
  {
    this->rear = this->rear->pre;
    this->rear->next = nullptr;
  }

  temp->pre = nullptr;

  delete temp;
}

void DEQueue::Traversal()
{
  cout << "Traversal: ";
  Node *ptr = this->front;
  while (ptr != nullptr)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }

  cout << endl;
}

bool DEQueue::isEmpty()
{
  return this->front == nullptr;
}
