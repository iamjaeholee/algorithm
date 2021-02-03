#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

int answer=INT_MAX;
int M, N;
std::tuple<int, int, int> destination;
std::pair<int, int> directions[4]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dCosts[4][4]{{0, 2, 1, 1}, {2, 0, 1, 1}, {1, 1, 0, 2}, {1, 1, 2, 0}};

void dfs(std::tuple<int, int, int>location, std::vector<std::vector<int>>& map, int count, int toggle) {
  int r, c, d, dr, dc, dd;
  std::tie(r, c, d) = location;
  std::tie(dr, dc, dd) = destination;
  if(r == dr && c == dc) {
    answer = std::min(answer, count+dCosts[d][dd]);
    return;
  }

  for(int i=0; i<4; i++) {
    int nextR = r + directions[i].first;
    int nextC = c + directions[i].second;
    if(nextR < 0 || nextR >= M || nextC < 0 || nextC >= N) continue;
    if(map[nextR][nextC] == 0) {
      map[r][c] = 1; // checker problem
      if(toggle == 1 && d == i) 
        dfs({nextR, nextC, i}, map, count+dCosts[d][i], toggle+1);
      else if(toggle == 2 && d==i)
        dfs({nextR, nextC, i}, map, count+dCosts[d][i], 0);
      else
        dfs({nextR, nextC, i}, map, count+dCosts[d][i] + 1, 1);
    }
  }

  return;
}

int main(){
  std::cin >> M >> N;
  std::vector<std::vector<int>> map;

  for(int i=0; i<M; i++) {
    std::vector<int> row;
    for(int j=0; j<N; j++) {
      int temp;
      std::cin >> temp;
      row.push_back(temp);
    }
    map.push_back(row);
  }

  int r, w, d;
  std::cin >> r >> w >> d;
  std::tuple<int, int, int> location = std::make_tuple(r-1, w-1, d-1);
  std::cin >> r >> w >> d;
  destination = std::make_tuple(r-1, w-1, d-1);

  dfs(location, map, 0, 0);

  std::cout << answer;

  return 0;
}