#include <iostream>

using namespace std;

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

class BST
{
  Node *root;

  void clear(Node *curr);
  bool search_helper(Node *curr, int key);
  void inorderTraversal(Node *rt);

public:
  BST();
  BST(int data);
  ~BST();

  void insert(int data);
  void search(int key);
  void traversal();
};

void BST::clear(Node *curr)
{
  if (curr == nullptr)
    return;

  clear(curr->left);
  clear(curr->right);

  delete curr;
}

bool BST::search_helper(Node *curr, int key)
{
  if (curr == nullptr)
    return false;

  if (key == curr->data)
    return true;
  else if (key < curr->data)
  {
    return search_helper(curr->left, key);
  }
  else
  {
    return search_helper(curr->right, key);
  }
}

void BST::inorderTraversal(Node *rt)
{
  if (rt != nullptr)
  {
    inorderTraversal(rt->left);
    cout << rt->data << " ";
    inorderTraversal(rt->right);
  }
}

BST::BST() : root(nullptr) {}

BST::BST(int data) : BST()
{
  this->insert(data);
}

BST::~BST()
{
  this->clear(this->root);
  this->root = nullptr;
}

void BST::insert(int data)
{
  if (this->root == nullptr)
  {
    Node *new_node = new Node{data, nullptr, nullptr};
    this->root = new_node;
    return;
  }

  Node *prev = nullptr;
  Node *curr = this->root;

  while (curr != nullptr)
  {
    prev = curr;
    if (data == curr->data)
    {
      cout << "This data is already in BST" << endl;
      return;
    }
    else if (data < curr->data)
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }
  }

  Node *new_node = new Node{data, nullptr, nullptr};
  if (data < prev->data)
  {
    prev->left = new_node;
  }
  else
  {
    prev->right = new_node;
  }
}

void BST::search(int key)
{
  Node *curr = this->root;
  bool is_found = this->search_helper(curr, key);
  is_found ? cout << key << " is found" << endl : cout << key << " Not found in BST";
}

void BST::traversal()
{
  this->inorderTraversal(this->root);
}
