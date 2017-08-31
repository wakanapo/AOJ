#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct node {
  int key;
  std::weak_ptr<node> parent;
  std::shared_ptr<node> left;
  std::shared_ptr<node> right;
  node(int k) : key(k), left(nullptr), right(nullptr) {};
};

class bst {
private:
  std::shared_ptr<node> root;
  void r_inorder(std::shared_ptr<node> n);
  void r_preorder(std::shared_ptr<node> n);
public:
  bst() : root(nullptr) {};
  void insert(int v);
  void print();
};

void bst::insert(int k) {
  std::shared_ptr<node> y = nullptr;
  std::shared_ptr<node> x = root;
  std::shared_ptr<node> z(new node(k));
  while (x != nullptr) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  z->parent = y;
  if (y == nullptr)
    root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

void bst::r_inorder(std::shared_ptr<node> n) {
  if (n == nullptr)
    return;
  r_inorder(n->left);
  std::cout << " " << n->key;
  r_inorder(n->right);
}

void bst::r_preorder(std::shared_ptr<node> n) {
  if (n == nullptr)
    return;
  std::cout << " " << n->key;
  r_preorder(n->left);
  r_preorder(n->right);
}

void bst::print() {
  r_inorder(root);
  std::cout << std::endl;
  r_preorder(root);
  std::cout << std::endl;
}

int main() {
  int n;
  std::cin >> n;
  bst tree;
  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    if (str == "insert") {
      int k;
      std::cin >> k;
      tree.insert(k);
    }
    else
      tree.print();
  }
}
