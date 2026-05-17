#include <iostream>
#include "CircularLinkList.cpp"

using namespace std;

int main()
{
  CList cl(23);
  cl.insert_at_end(9);
  cl.insert_at_end(4);
  cl.insert_at_end(1);
  cl.insert_at_pos(6, 2);
  cl.traversal();
  cl.delete_at_start();
  cl.delete_at_end();
  cl.traversal();
  return 0;
}