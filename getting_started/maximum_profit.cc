#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int maxv = -1000000000;
  int min = 2000000001;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    maxv = (a - min > maxv) ? a - min : maxv;
    min = (a < min) ? a : min;
  }
  std::cout << maxv << std::endl;
}
