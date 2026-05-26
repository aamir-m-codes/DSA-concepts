#include <iostream>
#include "DEQueue.cpp"

using namespace std;

int main()
{
  DEQueue q(83);

  q.enqueueR(30);
  q.enqueueR(82);
  q.Traversal();

  q.dequeueF();
  q.Traversal();

  q.enqueueF(1);
  q.Traversal();

  q.dequeueR();
  q.Traversal();

  return 0;
}