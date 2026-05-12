#include <iostream>
#include "StackUsingLL.cpp"

using namespace std;

int main()
{
  Stack s(4);
  s.push(5);
  s.push(6);
  cout << "Peak: " << s.peak() << endl;
  cout << "Pop: " << s.pop() << endl;
  cout << "Peak: " << s.peak() << endl;
  return 0;
}