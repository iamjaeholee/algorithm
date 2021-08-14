#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

bool checkSpace(const int& row, const int& col, const int& N, const int& M){
  return row >= 0 && row <N && col >= 0 && col <M ? true : false;
}

int main(){
  int N, M, K; std::cin >> N >> M >> K; std::cin.ignore();
  std::vector<std::string> map(N);

  for(int i=0; i<N; i++){
    getline(std::cin, map[i]);
  }

  std::vector<std::vector<std::pair<int, int>>> check;
  for(int i=0; i<N; i++) {
    std::vector<std::pair<int, int>> temp(M);
    check.push_back(temp);
  }

  check[0][0] = {1, -K};

  for(int i=1; i<N+M-1; i++){
    for(int j=0; j<=i; j++){
      int row=j; int col=i-j;
      if(checkSpace(row, col, N, M)){
        std::vector<std::pair<int, int>> temp;
        if(checkSpace(row-1, col, N, M) && check[row-1][col].second <= 0) temp.push_back(check[row-1][col]);
        if(checkSpace(row, col-1, N, M) && check[row][col-1].second <=0) temp.push_back(check[row][col-1]);
        if(temp.size() == 0) {
          check[row][col] = {10000, 1};
          continue;
        }
        std::sort(temp.begin(), temp.end());
        check[row][col] = map[row][col] == '0' ? std::make_pair(temp[0].first+1, temp[0].second) : std::make_pair(temp[0].first+1, temp[0].second+1);
      }
    }
  }


  check[N-1][M-1].second > 0 ? std::cout << -1 : std::cout << check[N-1][M-1].first;

  return 0;
}