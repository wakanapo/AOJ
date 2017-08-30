#include <iostream>
#include <vector>

std::vector<int> readVector(int n) {
  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    int id;
    std::cin >> id;
    v.push_back(id);
  }
  return v;
}

struct Tree {
  int left = -1;
  int right = -1;
};

struct SubVector {
  int begin;
  int end;
};

class Trees {
private:
  int root;
  std::vector<Tree> trees;
  std::vector<int> preordered;
  std::vector<int> inordered;
  int r_makeTree(SubVector pre, SubVector in);
  void r_postorderTreeWalk(int n);
public:
  Trees(std::vector<int>& pre, std::vector<int>& in, int n);
  std::vector<int> postordered;
  void makeTree();
  void postorderTreeWalk();
};

Trees::Trees(std::vector<int>& pre, std::vector<int>& in, int n) {
  trees = std::vector<Tree>(n);
  preordered = pre;
  inordered = in;
}

int Trees::r_makeTree(SubVector pre, SubVector in) {
  if (pre.end - pre.begin == 0)
    return -1;
  int r = preordered[pre.begin];
  if (pre.end - pre.begin == 1) {
    return r;
  }
  int partition = 0;
  for (int i = 0; i < in.end - in.begin; ++i) {
    if (inordered[in.begin + i] == r) {
      partition = i;
      break;
    }
  }
  trees[r-1].left = r_makeTree({pre.begin + 1, pre.begin + 1 + partition},
                             {in.begin, in.begin + partition});
  trees[r-1].right = r_makeTree({pre.begin + partition + 1, pre.end},
                              {in.begin + partition + 1, in.end});
  return r;
}

void Trees::makeTree() {
  root = r_makeTree({0, (int)preordered.size()}, {0, (int)inordered.size()});
}


void Trees::r_postorderTreeWalk(int n) {
  if (trees[n-1].left != -1)
    r_postorderTreeWalk(trees[n-1].left);
  if (trees[n-1].right != -1) {
    r_postorderTreeWalk(trees[n-1].right);
  }
  postordered.push_back(n);
}

void Trees::postorderTreeWalk() {
  r_postorderTreeWalk(root);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> preordered = readVector(n);
  std::vector<int> inordered = readVector(n);
  Trees t(preordered, inordered, n);
  t.makeTree();
  t.postorderTreeWalk();
  for (int i = 0; i < n; ++i)
    std::cout << t.postordered[i] << (i == n-1 ? "\n" : " ");
  return 0;
}
