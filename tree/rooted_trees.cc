#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

typedef struct {
  int parent = -1;
  int depth = 0;
  std::string type;
  std::vector<int> children;
} Node;

int main() {
  int n;
  std::cin >> n;
  std::vector<Node> tree(n);
  for (int i = 0; i < n; ++i) {
    int id, childs;
    std::cin >> id >> childs;
    for (int j = 0; j < childs; ++j) {
      int child;
      std::cin >> child;
      tree[id].children.push_back(child);
      tree[child].parent = id;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (tree[i].parent == -1) {
      tree[i].type = "root";
      std::queue<int> q;
      q.push(i);
      while(!q.empty()) {
        int id = q.front();  q.pop();
        tree[id].depth = (tree[id].parent == -1)
          ? 0 : (tree[tree[id].parent].depth + 1);
        for (int c : tree[id].children)
          q.push(c);
      }
    }
    else if (tree[i].children.size() > 0)
      tree[i].type = "internal node";
    else
      tree[i].type = "leaf";
  }
  for (int i = 0; i < n; ++i) {
    std::cout << "node " << i << ": parent = " << tree[i].parent <<
      ", depth = " << tree[i].depth << ", " << tree[i].type << ", [";
    for (int j = 0; j < (int)tree[i].children.size(); ++j)
      std::cout << tree[i].children[j] <<
        (j == (int)tree[i].children.size() - 1 ? "" : ", ");
    std::cout << "]" << std::endl;
  }
  return 0;
}
