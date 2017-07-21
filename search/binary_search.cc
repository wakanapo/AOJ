#include <iostream>
#include <vector>

bool bs(std::vector<int>& S, int t) {
  int left = 0;
  int right = S.size();
  while (left < right) {
    int target = (right + left) / 2;
    if (S[target] == t)
      return true;
    if (S[target] > t)
      right = target;
    else
      left = target + 1;
  }
  return false;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> S;
  for (int i = 0; i < n; ++i) {
    int s;
    std::cin >> s;
    S.push_back(s);
  }
  int q, cnt = 0;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int t;
    std::cin >> t;
    if (bs(S, t))
      ++cnt;
  }
  std::cout << cnt << std::endl;
}
