#include <iostream>
#include "CircularLinkList.cpp"

using namespace std;

int main()
{
  CList cl(23);
  cl.insertAtEnd(9);
  cl.insertAtEnd(4);
  cl.insertAtEnd(1);
  cl.insertAtPos(6, 2);
  cl.traversal();
  cl.deleteAtStart();
  cl.deleteAtEnd();
  cl.traversal();
  return 0;
}
