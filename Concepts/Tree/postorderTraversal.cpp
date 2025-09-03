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
void postorder(struct Node *node)
{
  if (node == NULL)
  {
    return;
  }
  postorder(node->left);
  postorder(node->right);
  cout << node->data << " ";
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
  cout << "Postorder traversal of binary tree is: \n";
  postorder(root);
  return 0;
}