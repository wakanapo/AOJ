#include <iostream>

int gcd(int x, int y) {
  int M = (x > y) ? x : y;
  int m = (x <= y) ? x : y;
  if (m == 0)
    return M;
  return gcd(m, M%m);
}

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << gcd(x, y) << std::endl;
}
