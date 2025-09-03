#include <iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *left, *right;
  Node(int x)
  {
    data = x;
    left = right = nullptr;
  }
};
void inorder(struct Node *node)
{
  if (node == NULL)
  {
    return;
  }
  inorder(node->left);
  cout << node->data << " ";
  inorder(node->right);
}
int main()
{
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  root->right->left = new Node(7);
  cout << "Inorder traversal of binary tree is: \n";
  inorder(root);
  return 0;
}