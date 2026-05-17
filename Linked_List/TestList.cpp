#include <iostream>
#include "linkList.cpp"

using namespace std;

int main()
{
  List l(5);
  l.insert_at_end(9);
  l.insert_at_end(4);
  l.insert_at_end(1);
  l.insert_at_position(6, 2);
  l.traversal();
  l.delete_at_start();
  l.delete_at_end();
  l.traversal();
  return 0;
}