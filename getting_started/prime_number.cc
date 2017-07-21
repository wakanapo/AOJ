#include <cmath>
#include <iostream>

bool isPrime(int n) {
  for (int i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n;
  std::cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if(isPrime(a))
      ++cnt;
  }
  std::cout << cnt << std::endl;
}
