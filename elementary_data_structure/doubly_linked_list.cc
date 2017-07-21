#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Node {
public:
  int key;
  std::shared_ptr<Node> next;
  std::shared_ptr<Node> pre;
  Node(int x): key(x), next(nullptr), pre(nullptr) {};
};

class List {
private:
  std::shared_ptr<Node> begin;
  std::shared_ptr<Node> end;
  std::unordered_map<int, int> exist;
public:
  List(): begin(nullptr), end(nullptr) {};
  void Insert(int x);
  void Delete(int x);
  void DeleteFirst();
  void DeleteLast();
  std::shared_ptr<Node> GetBegin();
};

void List::Insert(int x) {
  std::shared_ptr<Node> node(new Node(x));
  exist[x] = (exist.find(x) == exist.end()) ? 1 : exist[x] + 1;
  if (begin != nullptr) {
    begin->pre = node;
    node->next = begin;
  }
  begin = node;
  if (end == nullptr)
    end = node;
}

void List::Delete(int x) {
  std::shared_ptr<Node> node = begin;
  if (exist.find(x) == exist.end())
    return;
  else if (exist[x] > 1)
    exist[x] -= 1;
  else
    exist.erase(x);
  while (node != nullptr) {
    if (node->key == x) {
      if (node == begin) {
        node->next->pre = nullptr;
        begin = node->next;
        break;
      }
      else if (node == end) {
        node->pre->next = nullptr;
        end = node->pre;
        break;
      }
      else {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        break;
      }
    }
    node = node->next;
  }
}

void List::DeleteFirst() {
  if (begin->next != nullptr)
    begin->next->pre = nullptr;
  else
    end = nullptr;
  if (exist[begin->key] > 1)
    exist[begin->key] -=1;
  else
    exist.erase(begin->key);
  begin = begin->next;
}

void List::DeleteLast() {
  if (end->pre != nullptr)
    end->pre->next = nullptr;
  else
    begin = nullptr;
  if (exist[end->key] > 1)
    exist[end->key] -= 1;
  else
    exist.erase(end->key);
  end = end->pre;
}

std::shared_ptr<Node> List::GetBegin() {
  return begin;
}

int main() {
  std::string s;
  getline(std::cin, s);
  int n = std::stoi(s);
  List list;
  for (int i = 0; i < n; ++i) {
    std::string str;
    int x;
    getline(std::cin, str);
    std::string::size_type pos = str.find_first_of(" ");
    if (pos != std::string::npos) {
      x = std::stoi(std::string(str.begin() + pos + 1, str.end()));
      str = std::string(str.begin(), str.begin() + pos);
    }
    if (str == "insert")
      list.Insert(x);
    else if (str == "delete")
      list.Delete(x);
    else if (str == "deleteFirst")
      list.DeleteFirst();
    else if (str == "deleteLast")
      list.DeleteLast();
  }
  std::shared_ptr<Node> node = list.GetBegin();
  while (node != nullptr) {
    std::cout << node->key;
    node = node->next;
    std::cout << (node == nullptr ? "\n" : " ");
  }
}
