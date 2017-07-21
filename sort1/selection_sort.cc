#include <iostream>
#include <vector>

int selectionSort(std::vector<int>* a, int n) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (a->at(j) < a->at(minj)) 
        minj = j;
    }
    if (i != minj) {
      std::swap(a->at(i), a->at(minj));
      ++cnt;
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
  int ans = selectionSort(&as, n);
  for (int i = 0; i < n; ++i) {
    std::cout << as[i];
    if (i == n -1)
      std::cout << std::endl;
    else
      std::cout << " ";
  }
  std::cout << ans << std::endl;
}
