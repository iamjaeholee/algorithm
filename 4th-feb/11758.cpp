#include <iostream>

int main(){
  std::pair<int, int> p1{0, 0};
  std::pair<int, int> p2{0, 0};
  std::pair<int, int> p3{0, 0};
  std::cin >> p1.first >> p1.second;
  std::cin >> p2.first >> p2.second;
  std::cin >> p3.first >> p3.second;

  int tmp = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

  if(tmp < 0) std::cout << -1;
  if(tmp > 0) std::cout << 1;
  if(tmp == 0) std::cout << 0;

  return 0;
}