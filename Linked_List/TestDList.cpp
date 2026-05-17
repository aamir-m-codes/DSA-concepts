#include <iostream>
#include "DoublyLinkList.cpp"

using namespace std;

int main()
{
  DList dl(8);
  dl.insert_at_end(9);
  dl.insert_at_end(4);
  dl.insert_at_end(1);
  dl.insert_at_position(6, 2);
  dl.traversal(false);
  cout << endl;
  dl.delete_at_start();
  dl.delete_at_end();
  dl.traversal(true);
  return 0;
}