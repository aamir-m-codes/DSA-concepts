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

    void insert_at_start(int data);
    void insert_at_position(int data, int pos);
    void insert_at_end(int data);

    void delete_start();
    void delete_at_data(int data);
    void delete_end();
};

List::List()
{
    head = nullptr;
}

List::List(int data)
{
    head = nullptr;
    insert_at_start(data);
}

List::~List()
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void List::insert_at_start(int data)
{
    Node *temp = new Node{data, nullptr};
    temp->next = head;
    head = temp;
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
        insert_at_start(data);
        return;
    }
    Node *ptr = head;
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

    Node *temp = new Node{data, nullptr};
    temp->next = ptr->next;
    ptr->next = temp;
}

void List::insert_at_end(int data)
{
    Node *temp = new Node{data, nullptr};
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    Node *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void List::delete_start()
{
    if (head == nullptr)
    {
        cout << "List is already empty" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}

void List::delete_at_data(int data)
{
    if(head == nullptr)
    {
        cout<<"List is already empty"<<endl;
        return;
    }

    if(head->data == data)
    {
        delete_start();
        return;
    }

    Node *ptr = head;
    while(ptr->next != nullptr && ptr->next->data != data){
        ptr = ptr->next;
    }

    if(ptr->next == nullptr)
    {
        cout<<"Not Found"<<endl;
        return;
    }

    Node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next = nullptr;
    delete temp;
}

void List::delete_end()
{
    if (head == nullptr)
    {
        cout << "List is already empty" << endl;
        return;
    }

    if (head->next == nullptr)
    {
        delete_start();
        return;
    }

    Node *ptr = head;
    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }

    Node *temp = ptr->next;
    ptr->next = nullptr;
    temp->next = nullptr;
    delete temp;
}

int main()
{
    List l;
    l.insert_at_start(34);
    return 0;
}