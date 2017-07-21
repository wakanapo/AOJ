#include <iostream>
#include <stack>
#include <string>

int main() {
  std::stack<int> s;
  std::string str;
  getline(std::cin, str);
  int i = 0;
  while(1) {
    if (i >= (int)str.size())
      break;
    std::string::size_type j = str.find_first_of(' ', i);
    if (j == std::string::npos)
      j = str.size();
    std::string w = std::string(str.begin() + i, str.begin() + j);
    i = j + 1;
    if (w == "+" || w == "-" || w == "*") {
      int a = s.top(); s.pop();
      int b = s.top(); s.pop();
      if (w == "+")
        s.push(b + a);
      else if (w == "-")
        s.push(b - a);
      else if (w == "*")
        s.push(b * a);
    } else {
      int n = std::stoi(w);
      s.push(n);
    }
  }
  std::cout << s.top() << std::endl;;
}
