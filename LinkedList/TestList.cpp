#include <iostream>
#include "linkList.cpp"

using namespace std;

int main()
{
  List l(5);
  l.insertAtEnd(9);
  l.insertAtEnd(4);
  l.insertAtEnd(1);
  l.insertAtPosition(6, 2);
  l.traversal();
  l.deleteAtStart();
  l.deleteAtEnd();
  l.traversal();
  return 0;
}
