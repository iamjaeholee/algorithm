#include <iostream>
#include <string>

int main(){
  std::string S, K, changed;

  std::getline(std::cin, S);
  std::getline(std::cin, K);

  for(auto c: S){
    if(c >= 48 && c <= 57) continue;
    changed+=c;
  }

  changed.find(K) == std::string::npos ? std::cout << 0 : std::cout << 1;

  return 0;
}