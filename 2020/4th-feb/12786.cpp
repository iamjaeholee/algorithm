#include <iostream>
#include <vector>
#include <climits>

int N, K, answer=INT_MAX;

void go(std::vector<std::vector<int>>& v, int T, int height, int n){
  if(n == N) {
    answer = std::min(answer, T);
    return;
  }

  int amount = v[n].size();
  int check=0;

  for(int i=0; i<amount; i++){
    int nextHeight = v[n][i];
    if(height == nextHeight) {
      check=1;
      go(v, T, nextHeight, n+1); // O
    }
    if(height+1 == nextHeight) {
      check=1;
      go(v, T, nextHeight, n+1); // A
    }
    if(height >= 10 && 20 == nextHeight) {
      check=1;
      go(v, T, nextHeight, n+1); // B
    }
    if(height < 10 && height*2 == nextHeight){
      check=1;
      go(v, T, nextHeight, n+1); // B
    }
    if(height-1 == nextHeight){
      check=1;
      go(v, T, nextHeight, n+1); // C
    }
    if(check==0 && T<K) {
      check=1;
      go(v, T+1, nextHeight, n+1); // T
    }
  }

  if(check==0) answer=-1;
  return;
}

int main(){
  std::cin >> N >> K;
  std::vector<std::vector<int>> v;

  for(int i=0; i<N; i++){
    int M;
    std::cin >>  M;
    std::vector<int> tv;
    for(int j=0; j<M; j++) {
      int temp;
      std::cin >> temp;
      tv.push_back(temp);
    }
    v.push_back(tv);
  }

  go(v, 0, 1, 0);

  std::cout<<answer;

  return 0;
}