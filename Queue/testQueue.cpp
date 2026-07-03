#include <iostream>
#include "queue.cpp"

int main()
{
  Queue queue(45);
  queue.enqueue(39);
  queue.enqueue(10);
  queue.enqueue(91);
  queue.enqueue(78);
  queue.Traversal();
  queue.dequeue();
  queue.Traversal();

  return 0;
}
