#include <iostream>
#include "DEQueue.cpp"

using namespace std;

int main()
{
  DEQueue doubleEndedQ(83);

  doubleEndedQ.enqueueR(30);
  doubleEndedQ.enqueueR(82);
  doubleEndedQ.Traversal();

  doubleEndedQ.dequeueF();
  doubleEndedQ.Traversal();

  doubleEndedQ.enqueueF(1);
  doubleEndedQ.Traversal();

  doubleEndedQ.dequeueR();
  doubleEndedQ.Traversal();

  return 0;
}
