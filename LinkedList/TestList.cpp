#include <iostream>
#include "linkList.cpp"

using namespace std;

int main()
{
  List list(5);
  list.insertAtEnd(9);
  list.insertAtEnd(4);
  list.insertAtEnd(1);
  list.insertAtPosition(6, 2);
  list.traversal();
  list.deleteAtStart();
  list.deleteAtEnd();
  list.traversal();
  return 0;
}
