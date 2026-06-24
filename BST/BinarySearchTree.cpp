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
  void preorderTraversal(Node *rt);
  void postorderTraversal(Node *rt);
  Node *inorderPredecessor(Node *rt);
  Node *deletion_helper(Node *rt, int key);

public:
  BST();
  BST(int data);
  ~BST();

  void insert(int data);
  void search(int key);
  void traversal(int option = 0);
  void deletion(int key);
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

void BST::preorderTraversal(Node *rt)
{
  if (rt != nullptr)
  {
    cout << rt->data << " ";
    preorderTraversal(rt->left);
    preorderTraversal(rt->right);
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

void BST::postorderTraversal(Node *rt)
{
  if (rt != nullptr)
  {
    postorderTraversal(rt->left);
    postorderTraversal(rt->right);
    cout << rt->data << " ";
  }
}

Node *BST::inorderPredecessor(Node *rt)
{
  Node *temp = rt;
  if (temp == nullptr)
    return temp;

  temp = temp->left;
  while (temp->right != nullptr)
    temp = temp->right;

  return temp;
}

Node *BST::deletion_helper(Node *rt, int key)
{
  if (rt == nullptr)
    return nullptr;

  if (key < rt->data)
    rt->left = deletion_helper(rt->left, key);
  else if (key > rt->data)
    rt->right = deletion_helper(rt->right, key);
  else
  {
    if (rt->right == nullptr)
    {
      Node *temp = rt->left;
      delete rt;
      return temp;
    }
    else if (rt->left == nullptr)
    {
      Node *temp = rt->right;
      delete rt;
      return temp;
    }

    Node *inorderPre = this->inorderPredecessor(rt);
    rt->data = inorderPre->data;
    rt->left = deletion_helper(rt->left, inorderPre->data);
  }

  return rt;
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

void BST::traversal(int option)
{
  if (option == 0)
  {
    this->inorderTraversal(this->root);
  }
  else if (option == 1)
  {
    this->preorderTraversal(this->root);
  }
  else if (option == 2)
  {
    this->postorderTraversal(this->root);
  }
  cout << endl;
}

void BST::deletion(int key)
{
  this->root = this->deletion_helper(this->root, key);
}
