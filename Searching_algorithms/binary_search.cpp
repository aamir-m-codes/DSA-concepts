#include <iostream>

using namespace std;

int main()
{
  int arr[10] = {0, 2, 3, 4, 5, 6, 7, 9, 14, 17};
  int key = 9;
  int low = 0, high = 9;
  int mid;
  while (low < high)
  {
    mid = (low + high) / 2;
    if (arr[mid] == key)
    {
      cout << "Found at index " << mid << endl;
      break;
    }
    if (arr[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = low - 1;
    }
  }
  return 0;
}