#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>


int main() {
  int N;
  std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  char map[50][50];
  int checker[50][50];

  std::cin >> N;

  for(int i=0; i<N; i++) {
    std::cin >> map[i];
  }

  std::queue<std::pair<int, int>> q;


  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){{
      checker[i][j] = INT_MAX;
    }}
  }

  q.push({0, 0});
  checker[0][0] = 0;

  while(!q.empty()){
    std::pair<int, int> node = q.front();
    q.pop();

    for(int i=0; i<4; i++) {
      int row = node.first + directions[i].first;
      int column = node.second + directions[i].second;

      if(row < 0 || row >=N || column < 0 || column >=N) continue;

      if(map[row][column] == '0' && (checker[row][column] > (checker[node.first][node.second] + 1))) {
        checker[row][column] = checker[node.first][node.second] + 1; // check
        q.push({row, column}); // push
      }
      else if(map[row][column] == '1' && (checker[row][column] > checker[node.first][node.second])) {
        checker[row][column] = checker[node.first][node.second]; // check
        q.push({row, column}); // push
      }
    }
  }

  std::cout << checker[N-1][N-1];

  return 0;
}