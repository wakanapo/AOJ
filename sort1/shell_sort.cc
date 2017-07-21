#include <iostream>
#include <vector>


int insertionSort(std::vector<int>* a, int n, int g) {
  int cnt = 0;
  for (int i = g; i < n; ++i) {
    int v = (*a)[i];
    int j = i - g;
    while (j >= 0 && (*a)[j] > v) {
      (*a)[j + g] = (*a)[j];
      j = j - g;
      ++cnt;
    }
    (*a)[j + g] = v;
  }
  return cnt;
}

void shellSort(std::vector<int>* A, int n) {
  int cnt = 0;
  std::vector<int> G;
  int g = 1;
  G.push_back(g);
  while (1) {
    g = 3 * g + 1;
    if (g >= n)
      break;
    G.push_back(g);
  }
  for (int i = (int) G.size() - 1; i >= 0; --i) {
    cnt += insertionSort(A, n, G[i]);
  }
  std::cout << G.size() << std::endl;
  for (int i = (int) G.size() - 1; i >= 0; --i)
    std::cout << G[i] << (i == 0 ? "\n" : " ");
  std::cout << cnt << std::endl;
  for (int a : *A)
    std::cout << a << std::endl;
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
  shellSort(&as, n);
}
