#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> as;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    as.push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    int target = as[i];
    for (int j = 0; j < i; ++j) {
      if (as[j] > target) {
        as.erase(as.begin() + i);
        as.insert(as.begin() + j, target);
         break;
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << as[i];
      if (i == n - 1)
        std::cout << std::endl;
      else
        std::cout << " ";
    }
  }
}
