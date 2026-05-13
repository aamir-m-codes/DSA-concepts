#include <iostream>
#include "StackUsingArray.cpp"

using namespace std;

int main()
{
  Stack s(6);
  s.push(7);
  s.push(5);
  s.push(3);
  s.push(4);
  s.push(2);
  s.push(1);
  cout << "Top: " << s.peak() << endl;
  cout << "Capacity: " << s.getCapacity() << endl;
  s.push(10);
  cout << "Capacity: " << s.getCapacity() << endl;
  return 0;
}