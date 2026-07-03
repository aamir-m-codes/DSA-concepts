#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *pre;
  struct Node *next;
} Node;

class DList
{
  Node *head, *tail;

public:
  DList();
  DList(int data);
  ~DList();
  /*
  these both lines prevent to copy the two objects on same memory location that
  cause double free -> crash while deleting or freeing memory in destructor
  */
  DList(const DList &) = delete;
  DList &operator=(const DList &) = delete;

  void traversal(bool reverse);

  void insertAtStart(int data);
  void insertAtPosition(int data, int pos);
  void insertAtEnd(int data);

  void deleteAtStart();
  void deleteAtData(int data);
  void deleteAtEnd();
};

DList::DList()
{
  this->head = nullptr;
  this->tail = nullptr;
}

DList::DList(int data)
{
  this->head = nullptr;
  this->tail = nullptr;
  this->insertAtStart(data);
}

DList::~DList()
{
  Node *temp;
  while (this->head != nullptr)
  {
    temp = this->head;
    this->head = this->head->next;
    delete temp;
  }
  this->tail = nullptr;
}

void DList::traversal(bool reverse)
{
  Node *ptr;
  if (reverse)
  {
    cout << "Backward: ";
    ptr = this->tail;
    while (ptr)
    {
      cout << ptr->data << "  " << endl;
      ptr = ptr->pre;
    }
  }
  else
  {
    cout << "Forward: ";
    ptr = this->head;
    while (ptr)
    {
      cout << ptr->data << "  " << endl;
      ptr = ptr->next;
    }
  }
}

void DList::insertAtStart(int data)
{
  Node *new_node = new Node{data, nullptr, this->head};

  if (this->head == nullptr)
  {
    this->tail = new_node;
  }
  else
  {
    this->head->pre = new_node;
  }

  this->head = new_node;
}

void DList::insertAtPosition(int data, int pos)
{
  if (pos <= 0)
  {
    cout << "Invalid Position (must > 0) " << endl;
    return;
  }

  if (pos == 1)
  {
    this->insertAtStart(data);
    return;
  }

  int i = 1;
  Node *temp = this->head;
  while (i < pos - 1 && temp != nullptr)
  {
    temp = temp->next;
    i++;
  }

  if (temp == nullptr)
  {
    cout << "Position is out of bound" << endl;
    return;
  }

  if (temp->next == nullptr)
  {
    this->insertAtEnd(data);
    return;
  }

  Node *new_node = new Node{data, temp, temp->next};
  temp->next->pre = new_node;
  temp->next = new_node;
}

void DList::insertAtEnd(int data)
{
  Node *new_node = new Node{data, this->tail, nullptr};
  if (this->tail == nullptr)
  {
    this->head = new_node;
  }
  else
  {
    this->tail->next = new_node;
  }

  this->tail = new_node;
}

void DList::deleteAtStart()
{
  if (this->head == nullptr)
  {
    cout << "List is already empty" << endl;
    return;
  }

  Node *temp = this->head;
  this->head = this->head->next;
  temp->next = nullptr;

  if (this->head == nullptr)
  {
    this->tail = nullptr;
  }
  else
  {
    this->head->pre = nullptr;
  }
  delete temp;
}

void DList::deleteAtData(int data)
{
  if (this->head == nullptr)
  {
    cout << "List is already empty" << endl;
    return;
  }

  if (this->head->data == data)
  {
    this->deleteAtStart();
    return;
  }

  if (this->tail->data == data)
  {
    this->deleteAtEnd();
    return;
  }

  Node *ptr = this->head;
  while (ptr != nullptr && ptr->data != data)
  {
    ptr = ptr->next;
  }

  if (ptr == nullptr)
  {
    cout << "Not such node exist in list" << endl;
    return;
  }

  ptr->pre->next = ptr->next;
  ptr->next->pre = ptr->pre;

  ptr->next = nullptr;
  ptr->pre = nullptr;

  delete ptr;
}

void DList::deleteAtEnd()
{
  if (this->tail == nullptr)
  {
    cout << "List is already empty" << endl;
    return;
  }

  Node *temp = this->tail;
  this->tail = this->tail->pre;
  temp->pre = nullptr;

  if (this->tail == nullptr)
  {
    this->head = nullptr;
  }
  else
  {
    this->tail->next = nullptr;
  }

  delete temp;
}
