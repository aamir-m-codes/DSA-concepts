#include <iostream>
#include "stackUsingLL.cpp"

using namespace std;

int main()
{
  Stack stack(4);
  stack.push(5);
  stack.push(6);
  cout << "Peak: " << stack.peak() << endl;
  cout << "Pop: " << stack.pop() << endl;
  cout << "Peak: " << stack.peak() << endl;
  return 0;
}
