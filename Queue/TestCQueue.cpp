#include <iostream>
#include "CircularQueue.cpp"

using namespace std;

int main()
{
  CQueue cq(37);
  cq.enqueue(30);
  cq.enqueue(82);
  cq.Traversal();

  cq.dequeue();
  cq.dequeue();
  cq.Traversal();

  cq.enqueue(2);
  cq.enqueue(9);
  cq.Traversal();
  return 0;
}
