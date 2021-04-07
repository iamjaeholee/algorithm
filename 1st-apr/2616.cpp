#include <iostream>
#include <vector>

int main(){
  int N;
  std::cin >> N;
  std::vector<int> train(N+1, 0), sum(N+1, 0);
  std::vector<std::vector<int>> DP;

  for(int i=1; i<=N; i++){
    std::cin >> train[i];
    sum[i] = sum[i-1] + train[i];
  }

  int capa;
  std::cin >> capa;

  for(int i=0; i<=3; i++){
    std::vector<int> temp(N+1, 0);
    DP.push_back(temp);
  }

  for(int i=1; i<=3; i++){
    for(int j=i*capa; j<=N; j++){
      if(i == 1)
      DP[i][j] = std::max(DP[i][j-1], sum[j]-sum[j-capa]);
      else
      DP[i][j] = std::max(DP[i][j-1], DP[i-1][j-capa] + sum[j]-sum[j-capa]);
    }
  }

  std::cout << DP[3][N];

  return 0;
}