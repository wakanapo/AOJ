#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> S;
  for (int i = 0; i < n; ++i) {
    int s;
    std::cin >> s;
    S.push_back(s);
  }
  int q;
  std::cin >> q;
  int cnt = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    std::cin >> t;
    for (int s : S) {
      if (s == t) {
        ++cnt;
        break;
      } 
    }
  }
  std::cout << cnt << std::endl;
}
