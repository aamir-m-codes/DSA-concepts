#include <iostream>
#include "StackUsingArray.cpp"

using namespace std;

int main()
{
  Stack stack(6);
  stack.push(7);
  stack.push(5);
  stack.push(3);
  stack.push(4);
  stack.push(2);
  stack.push(1);
  cout << "Top: " << stack.peak() << endl;
  cout << "Capacity: " << stack.getCapacity() << endl;
  stack.push(10);
  cout << "Capacity: " << stack.getCapacity() << endl;
  return 0;
}
