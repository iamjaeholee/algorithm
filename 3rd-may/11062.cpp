#include <iostream>
#include <vector>

int main(){
  int T;
  std::cin >> T;

  while(T--){
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    int answer=0;
    for(int i=0; i<N; i++) std::cin >> v[i];
    for(int i=0; i<N; i++){
      std::vector<int>::iterator it1 = v.begin();
      std::vector<int>::iterator it2 = v.end()-1;
      if(*it2 > *it1) {
        if(i%2 == 0) answer += *it2;
        it2 = it2-1;
      } else {
        if(i%2 == 0) answer += *it1;
        it1 = it1+1;
      }
    }

    std::cout << answer << std::endl;
  }

  return 0;
}