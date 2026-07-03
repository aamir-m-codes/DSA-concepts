#include <iostream>
#include "circularLinkList.cpp"

using namespace std;

int main()
{
  CList circularLL(23);
  circularLL.insertAtEnd(9);
  circularLL.insertAtEnd(4);
  circularLL.insertAtEnd(1);
  circularLL.insertAtPos(6, 2);
  circularLL.traversal();
  circularLL.deleteAtStart();
  circularLL.deleteAtEnd();
  circularLL.traversal();
  return 0;
}
