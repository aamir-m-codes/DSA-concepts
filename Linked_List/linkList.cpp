#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

class List
{
  Node *head;

public:
  List();
  List(int data);
  ~List();

  /*

  these both lines prevent to copy the two objects on same memory location that
  cause double free -> crash while deleting or freeing memory in destructor

  */
  List(const List &) = delete;
  List &operator=(const List &) = delete;

  void traversal();

  void insert_at_start(int data);
  void insert_at_position(int data, int pos);
  void insert_at_end(int data);

  void delete_at_start();
  void delete_at_data(int data);
  void delete_at_end();
};

List::List()
{
  this->head = nullptr;
}

List::List(int data)
{
  this->head = nullptr;
  this->insert_at_start(data);
}

List::~List()
{
  Node *temp;
  while (this->head != nullptr)
  {
    temp = this->head;
    this->head = this->head->next;
    delete temp;
  }
}

void List::traversal()
{
  Node *ptr = this->head;
  cout << "List: ";
  while (ptr)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
}

void List::insert_at_start(int data)
{
  Node *temp = new Node{data, nullptr};
  temp->next = this->head;
  this->head = temp;
}

void List::insert_at_position(int data, int pos)
{
  if (pos <= 0)
  {
    cout << "Invalid Position" << endl;
    return;
  }

  if (pos == 1)
  {
    this->insert_at_start(data);
    return;
  }
  Node *ptr = this->head;
  int i = 1;

  while (i < pos - 1 && ptr != nullptr)
  {
    ptr = ptr->next;
    i++;
  }

  if (ptr == nullptr)
  {
    cout << "Position out of bound" << endl;
    return;
  }

  Node *new_node = new Node{data, nullptr};
  new_node->next = ptr->next;
  ptr->next = new_node;
}

void List::insert_at_end(int data)
{
  Node *temp = new Node{data, nullptr};
  if (this->head == nullptr)
  {
    this->head = temp;
    return;
  }
  Node *ptr = this->head;
  while (ptr->next != nullptr)
  {
    ptr = ptr->next;
  }

  ptr->next = temp;
}

void List::delete_at_start()
{
  if (this->head == nullptr)
  {
    cout << "List is already empty" << endl;
    return;
  }

  Node *temp = this->head;
  this->head = this->head->next;
  temp->next = nullptr;
  delete temp;
}

void List::delete_at_data(int data)
{
  if (this->head == nullptr)
  {
    cout << "List is already empty" << endl;
    return;
  }

  if (this->head->data == data)
  {
    this->delete_at_start();
    return;
  }

  Node *ptr = this->head;
  while (ptr->next != nullptr && ptr->next->data != data)
  {
    ptr = ptr->next;
  }

  if (ptr->next == nullptr)
  {
    cout << "Not Found" << endl;
    return;
  }

  Node *temp = ptr->next;
  ptr->next = temp->next;
  temp->next = nullptr;
  delete temp;
}

void List::delete_at_end()
{
  if (this->head == nullptr)
  {
    cout << "List is already empty" << endl;
    return;
  }

  if (this->head->next == nullptr)
  {
    this->delete_at_start();
    return;
  }

  Node *ptr = this->head;
  while (ptr->next->next != nullptr)
  {
    ptr = ptr->next;
  }

  Node *temp = ptr->next;
  ptr->next = nullptr;
  temp->next = nullptr;
  delete temp;
}
