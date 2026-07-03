#include <iostream>
#include "doublyLinkList.cpp"

using namespace std;

int main()
{
  DList doublyLL(8);
  doublyLL.insertAtEnd(9);
  doublyLL.insertAtEnd(4);
  doublyLL.insertAtEnd(1);
  doublyLL.insertAtPosition(6, 2);
  doublyLL.traversal(false);
  cout << endl;
  doublyLL.deleteAtStart();
  doublyLL.deleteAtEnd();
  doublyLL.traversal(true);
  return 0;
}
