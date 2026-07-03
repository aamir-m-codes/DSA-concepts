#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

class CList
{
  Node *head, *tail;

public:
  CList();
  CList(int data);
  ~CList();
  /*
  these both lines prevent to copy the two objects on same memory location that
  cause double free -> crash while deleting or freeing memory in destructor
  */
  CList(const CList &) = delete;
  CList &operator=(const CList &) = delete;

  void traversal();

  void insertAtStart(int data);
  void insertAtPos(int data, int pos);
  void insertAtEnd(int data);

  void deleteAtStart();
  void deleteAtData(int data);
  void deleteAtEnd();
};

CList::CList()
{
  this->head = nullptr;
  this->tail = nullptr;
}

CList::CList(int data)
{
  this->head = nullptr;
  this->tail = nullptr;
  this->insertAtStart(data);
}

CList::~CList()
{
  if (this->head == nullptr)
    return;

  this->tail->next = nullptr;

  Node *temp;
  while (this->head)
  {
    temp = this->head;
    this->head = this->head->next;
    delete temp;
  }

  this->tail = nullptr;
}

void CList::traversal()
{
  Node *ptr = this->head;
  cout << "List: ";
  do
  {
    cout << ptr->data << endl;
    ptr = ptr->next;
  } while (ptr != this->head);
}

void CList::insertAtStart(int data)
{
  Node *new_node = new Node{data, this->head};
  if (this->head == nullptr)
  {
    this->tail = new_node;
  }
  this->head = new_node;
  this->tail->next = this->head;
}

void CList::insertAtPos(int data, int pos)
{
  if (pos <= 0)
  {
    cout << "Invalid Position (must > 0)" << endl;
    return;
  }

  if (pos == 1)
  {
    this->insertAtStart(data);
    return;
  }

  if (this->head == nullptr)
  {
    cout << "Position out of bounds (List is empty)" << endl;
    return;
  }

  int i = 1;
  Node *temp = this->head;

  while (i < pos - 1)
  {
    temp = temp->next;
    i++;

    if (temp == this->head)
    {
      cout << "Position out of bounds" << endl;
      return;
    }
  }

  if (temp == this->tail)
  {
    this->insertAtEnd(data);
    return;
  }

  Node *new_node = new Node{data, temp->next};
  temp->next = new_node;
}

void CList::insertAtEnd(int data)
{
  Node *new_node = new Node{data, this->head};
  if (this->head == nullptr)
  {
    this->insertAtStart(data);
    return;
  }

  this->tail->next = new_node;
  this->tail = new_node;
  this->tail->next = this->head;
}

void CList::deleteAtStart()
{
  if (this->head == nullptr)
  {
    cout << "List already empty" << endl;
    return;
  }

  Node *temp = this->head;
  if (this->head == this->tail)
  {
    this->head = nullptr;
    this->tail = nullptr;
  }
  else
  {
    this->head = this->head->next;
    this->tail->next = this->head;
  }

  temp->next = nullptr;
  delete temp;
}

void CList::deleteAtData(int data)
{
  if (this->head == nullptr)
  {
    cout << "List already empty" << endl;
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

  Node *temp = this->head;
  Node *ptr = this->head;
  while (ptr->next->data != data && ptr->next != this->tail)
  {
    ptr = ptr->next;
  }

  if (ptr->next == this->tail)
  {
    cout << "No such node exist in the list" << endl;
    return;
  }

  temp = ptr->next;
  ptr->next = temp->next;

  temp->next = nullptr;
  delete temp;
}

void CList::deleteAtEnd()
{
  if (this->head == nullptr)
  {
    cout << "List already empty" << endl;
    return;
  }

  Node *temp = this->head;
  if (this->head == this->tail)
  {
    this->head = nullptr;
    this->tail = nullptr;
  }
  else
  {
    Node *ptr = this->head;
    while (ptr->next != this->tail)
    {
      ptr = ptr->next;
    }

    temp = ptr->next;
    ptr->next = this->head;
    this->tail = ptr;
  }

  temp->next = nullptr;
  delete temp;
}
