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

  void insert_at_start(int data);
  void insert_at_pos(int data, int pos);
  void insert_at_end(int data);

  void delete_at_start();
  void delete_at_data(int data);
  void delete_at_end();
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
  this->insert_at_start(data);
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

void CList::insert_at_start(int data)
{
  Node *new_node = new Node{data, this->head};
  if (this->head == nullptr)
  {
    this->tail = new_node;
  }
  this->head = new_node;
  this->tail->next = this->head;
}

void CList::insert_at_pos(int data, int pos)
{
  if (pos <= 0)
  {
    cout << "Invalid Position (must > 0)" << endl;
    return;
  }

  if (pos == 1)
  {
    this->insert_at_start(data);
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
    this->insert_at_end(data);
    return;
  }

  Node *new_node = new Node{data, temp->next};
  temp->next = new_node;
}

void CList::insert_at_end(int data)
{
  Node *new_node = new Node{data, this->head};
  if (this->head == nullptr)
  {
    this->insert_at_start(data);
    return;
  }

  this->tail->next = new_node;
  this->tail = new_node;
  this->tail->next = this->head;
}

void CList::delete_at_start()
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

void CList::delete_at_data(int data)
{
  if (this->head == nullptr)
  {
    cout << "List already empty" << endl;
    return;
  }

  if (this->head->data == data)
  {
    this->delete_at_start();
    return;
  }

  if (this->tail->data == data)
  {
    this->delete_at_end();
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

void CList::delete_at_end()
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
