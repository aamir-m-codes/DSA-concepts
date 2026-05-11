#include <iostream>

using namespace std;

typedef struct list
{
    int data;
    struct list *next;
} l;

void traversal(l *head)
{
    l *ptr = head;
    do
    {
        cout << "List: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

l *insertionAtFirst(l *head, int value)
{
    l *ptr = new l();
    ptr->data = value;

    l *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    l *head;
    l *second;
    l *third;
    l *fourth;

    head = new l();
    second = new l();
    third = new l();
    fourth = new l();

    head->data = 3;
    head->next = second;

    second->data = 74;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 41;
    fourth->next = head;

    cout << "Before insertion" << endl;
    traversal(head);
    head = insertionAtFirst(head, 99);
    cout << "After insertion" << endl;
    traversal(head);

    return 0;
}