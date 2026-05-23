#include <iostream>
#include "Queue.cpp"

int main()
{
  Queue q(45);
  q.enqueue(39);
  q.enqueue(10);
  q.enqueue(91);
  q.enqueue(78);
  q.Traversal();
  q.dequeue();
  q.Traversal();

  return 0;
}