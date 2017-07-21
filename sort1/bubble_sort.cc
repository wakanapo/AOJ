#include <iostream>
#include <vector>

int bubbleSort(std::vector<int>* v, int n) {
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1 -i; ++j) {
      if (v->at(j) > v->at(j + 1)) {
        std::swap(v->at(j), v->at(j+1));
        ++cnt;
      }
    }
  }
  return cnt;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> as;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    as.push_back(a);
  }
  int ans = bubbleSort(&as, n);
  for (int i = 0; i < n; ++i) {
    std::cout << as[i];
    if (i == n-1)
      std::cout << std::endl;
    else
      std::cout << " ";
  }
  std::cout << ans << std::endl;
}
