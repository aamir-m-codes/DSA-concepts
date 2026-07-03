#include <iostream>

using namespace std;

int main()
{
  int arr[10] = {3, 5, 2, 1, 5, 6, 8, 9, 7, 0};
  int key = 6;
  for (int i = 0; i < 10; i++)
  {
    if (arr[i] == key)
    {
      cout << "Found at index " << i << endl;
      break;
    }
  }

  return 0;
}