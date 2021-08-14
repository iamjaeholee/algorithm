#include <iostream>
#include <vector>
#include <algorithm>

bool myfunction (int i,int j) { return (i>j); }

int main(){
  int N, R=0, B=0;
  std::cin >> N;
  std::vector<int> v;

  for(int i=0; i<N; i++) {
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  for(int i=1; i<N; i++) {
    std::vector<int> tv = v;
    std::sort(tv.begin(), tv.begin()+i, myfunction);
    std::sort(tv.begin()+i, tv.end(), myfunction);
    if(tv[0] > tv[i]) R++;
    if(tv[i] > tv[0]) B++;
  }

  if(R > B) std::cout << 'R';
  if(R == B) std::cout << 'X';
  if(R < B) std::cout << 'B';

  return 0;
}