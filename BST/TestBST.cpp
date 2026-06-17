#include <iostream>
#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
  BST bst;
  bst.insert(45);
  bst.insert(89);
  bst.insert(12);
  bst.insert(70);
  bst.insert(9);

  // it print in sorted order due to BST nature
  bst.traversal();
  bst.search(70);
  bst.search(30);
  return 0;
}