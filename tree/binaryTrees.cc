#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>

typedef struct {
  int parent = -1;
  int sibling = -1;
  int degree = 0;
  int depth = 0;
  int height = 0;
  std::string type;
  std::vector<int> children;
} Node;

int main() {
  int n;
  std::cin >> n;
  std::vector<Node> tree(n);
  for (int i = 0; i < n; ++i) {
    int id, left, right;
    std::cin >> id >> left >> right;
    if (left != -1) {
      tree[id].children.push_back(left);
      tree[left].parent = id;
      tree[left].sibling = right;
    }
    if (right != -1) {
      tree[id].children.push_back(right);
      tree[right].parent = id;
      tree[right].sibling = left;
    }
  }
  std::stack<int> s;
  for (int i = 0; i < n; ++i) {
    if (tree[i].parent == -1) {
      std::queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int id = q.front(); q.pop();
        tree[id].depth = (id == i) ? 0 : (tree[tree[id].parent].depth + 1);
        for (int child : tree[id].children)
          q.push(child);
        s.push(id);
      }
      break;
    }
  }
  int id;
  while (!s.empty()) {
    id = s.top(); s.pop();
    if (tree[id].children.size() == 0) {
      tree[id].degree = 0;
      tree[id].height = 0;
      tree[id].type = "leaf";
    }
    else if (tree[id].children.size() == 1) {
      tree[id].degree = 1;
      tree[id].height = tree[tree[id].children[0]].height + 1;
      tree[id].type = "internal node";
    }
    else {
      tree[id].degree = 2;
      tree[id].height = std::max(tree[tree[id].children[0]].height,
                                 tree[tree[id].children[1]].height) + 1;
      tree[id].type = "internal node";
    }
  }
  tree[id].type = "root";
  for (int i = 0; i < n; ++i)
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, \
height = %d, %s\n", i, tree[i].parent, tree[i].sibling, tree[i].degree,
           tree[i].depth, tree[i].height, tree[i].type.c_str());
  return 0;
}
