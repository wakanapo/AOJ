#include <iostream>
#include <string>
#include <queue>

class Process {
public:
  std::string name;
  int time;
  Process(std::string n, int t): name(n), time(t) {};
};

int main() {
  int n, q;
  std::cin >> n >> q;
  std::queue<Process*> ps;
  for (int i = 0; i < n; ++i) {
    std::string name;
    int time;
    std::cin >> name >> time; 
    ps.push(new Process(name, time));
  }
  int time = 0;
  while (ps.size() > 0) {
    Process* p = ps.front(); ps.pop();
    time += (p->time > q) ? q : p->time;
    p->time -= q;
    if (p->time <= 0)
      std::cout << p->name << " " << time << std::endl;
    else
      ps.push(p);
  }
}
