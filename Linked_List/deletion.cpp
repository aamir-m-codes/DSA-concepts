#include <iostream>

using namespace std;

typedef struct list
{
    int data;
    struct list *next;
} l;

void Traversal(struct list *l)
{
    while (l != NULL)
    {
        cout << "Value: " << l->data << endl;
        l = l->next;
    }
}

l *deleteFirst(l *head)
{
    l *ptr = head;
    head = head->next;
    return head;
}

l *deleteAtIndex(l *head, int index)
{
    l *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    l *p = ptr->next;
    cout << "*p :" << p->data << endl;
    ptr->next = p->next;

    return head;
}

l *deleteAtKey(l *head, int value)
{
    l *ptr = head;
    l *p = head->next;
    while (ptr->data != value && p->data != value && p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
        cout << "Loop" << endl;
    }
    if (p->data == value)
    {
        ptr->next = p->next;
    }
    else if (ptr->data == value)
    {
        head = head->next;
    }
    return head;
}

l *deleteAtEnd(l *head)
{
    l *ptr = head;
    l *p = ptr->next;
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = NULL;

    return head;
}

int main()
{
    l *first;
    l *second;
    l *third;
    l *fourth;

    first = new l();
    second = new l();
    third = new l();
    fourth = new l();

    first->data = 20;
    first->next = second;

    second->data = 89;
    second->next = third;

    third->data = 71;
    third->next = fourth;

    fourth->data = 38;
    fourth->next = NULL;

    cout << "Before Deletion" << endl;
    Traversal(first);
    // first = deleteFirst(first); //? First element delete in linked list
    // first = deleteAtIndex(first, 1); //? Deletion at index in linked list
    first = deleteAtKey(first, 20); //? Deletion at value in linked list
    // first = deleteAtEnd(first); //? Last element delete in linked list
    cout << "After Deletion" << endl;
    Traversal(first);

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}