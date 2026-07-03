#include <iostream>
#include "binarySearchTree.cpp"

using namespace std;

int main()
{
  BST bst;
  bst.insert(45);
  bst.insert(89);
  bst.insert(12);
  bst.insert(70);
  bst.insert(9);

  // traversal take one argument of type int it expect only 0 -> inorder, 1 -> preorder, 2-> postorder for traversal
  bst.traversal();
  bst.search(70);
  bst.search(30);
  bst.deletion(12);
  cout << "After deletion: ";
  bst.traversal();
  return 0;
}
