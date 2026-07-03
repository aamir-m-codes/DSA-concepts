#include <iostream>
#include "DoublyLinkList.cpp"

using namespace std;

int main()
{
  DList dl(8);
  dl.insertAtEnd(9);
  dl.insertAtEnd(4);
  dl.insertAtEnd(1);
  dl.insertAtPosition(6, 2);
  dl.traversal(false);
  cout << endl;
  dl.deleteAtStart();
  dl.deleteAtEnd();
  dl.traversal(true);
  return 0;
}
