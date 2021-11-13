#include <iostream>
#include <string>
#include <algorithm>

int main(){
  std::string S, T;

  std::getline(std::cin, S);
  std::getline(std::cin, T);

  while(S.size() != T.size()){
    int lastIndex = T.size()-1;
    if(T[lastIndex] == 'A'){
      T.erase(T.end()-1, T.end());
    } else if(T[lastIndex] == 'B'){
      T.erase(T.end()-1, T.end());
      std::reverse(T.begin(), T.end());
    }
  }

  if(S == T) std::cout<<1;
  else std::cout<<0;
  return 0;
}