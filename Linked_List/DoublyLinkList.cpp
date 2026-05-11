#include <iostream>

using namespace std;

typedef struct list
{
    int data;
    struct list *pre;
    struct list *next;
} l;

void Traversal(l *head)
{
    cout << "Forward: " << endl;
    l *ptr = head;
    do
    {
        cout << "List: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr->next != NULL);
    cout << "List: " << ptr->data << endl;
    cout << " Backward: " << endl;

    do
    {
        cout << "List: " << ptr->data << endl;
        ptr = ptr->pre;
    } while (ptr->pre != NULL);
    cout << "List: " << ptr->data << endl;

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

    head->data = 82;
    head->pre = NULL;
    head->next = second;

    second->data = 33;
    second->pre = head;
    second->next = third;

    third->data = 40;
    third->pre = second;
    third->next = fourth;

    fourth->data = 91;
    fourth->pre = third;
    fourth->next = NULL;

    Traversal(head);

    return 0;
}