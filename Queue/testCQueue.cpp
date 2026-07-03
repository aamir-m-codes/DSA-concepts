#include <iostream>
#include "circularQueue.cpp"

using namespace std;

int main()
{
  CQueue circularQ(37);
  circularQ.enqueue(30);
  circularQ.enqueue(82);
  circularQ.Traversal();

  circularQ.dequeue();
  circularQ.dequeue();
  circularQ.Traversal();

  circularQ.enqueue(2);
  circularQ.enqueue(9);
  circularQ.Traversal();
  return 0;
}
