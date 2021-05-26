#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>
#include <climits>
#include <algorithm>

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void findDirtySpace(std::vector<std::string>& map, const int& w, const int& h, std::vector<std::tuple<int, int, int>>& dirtySpaces, std::pair<int, int>& start){
  int counter = 1;
  for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
    if(map[i][j] == '*') dirtySpaces.push_back({i, j, counter++});
    else if(map[i][j] == 'o') start = {i, j};
  }
}

bool compairFunc(std::tuple<int, int, int>& a, std::tuple<int, int, int>& b){
  return std::get<2>(a) < std::get<2>(b);
}

int bfs(std::vector<std::string>& map, const int&w, const int& h, const std::pair<int, int>& start, const std::pair<int, int>& end){
  std::vector<int> checkW(w, -1);
  std::vector<std::vector<int>> checker(h, checkW);

  std::queue<std::pair<int, int>> q;
  q.push(start);
  checker[start.first][start.second] = 0;

  while(!q.empty()){
    std::pair<int, int> node = q.front();
    q.pop();

    for(auto d: directions){
      int nextH = node.first + d[0];
      int nextW = node.second + d[1];

      if(nextH == end.first && nextW == end.second) return checker[node.first][node.second] + 1; // 목적지를 찾았을 때 최적거리 리턴 

      if(nextH >= 0 && nextH < h && nextW >= 0 && nextW < w && checker[nextH][nextW] == -1 && map[nextH][nextW] != 'x') {
        checker[nextH][nextW] = checker[node.first][node.second] + 1;
        std::pair<int, int> nextNode = {nextH, nextW};
        q.push(nextNode);
      }
    }
  }

  return -1;
}

int main(){
  int w, h;

  while(std::cin >> w >> h){
    // 종료 조건
    if(w == 0 && h == 0) break; 

    // 맵 만들기
    std::vector<std::string> map(h);
    for(int i=0; i<h; i++) std::getline(std::cin >> std::ws, map[i]); 

    // 더러운 칸 찾기
    std::pair<int, int> start;
    std::vector<std::tuple<int, int, int>> dirtySpaces;
    findDirtySpace(map, w, h, dirtySpaces, start); 

    // 순열 돌리기
    int answer = INT_MAX;
    do {
      int dirtySpaceLength = dirtySpaces.size();
      int check = 1, tempAnswer = 0;
      for(int i=0; i<dirtySpaceLength; i++){
        // BFS로 부분 거리 최솟값 구하기
        int result;
        i == 0 ? result = bfs(map, w, h, start, {std::get<0>(dirtySpaces[0]), std::get<1>(dirtySpaces[0])}) :
          result = bfs(map, w, h, {std::get<0>(dirtySpaces[i-1]), std::get<1>(dirtySpaces[i-1])}, {std::get<0>(dirtySpaces[i]), std::get<1>(dirtySpaces[i])});

        if(result == -1) {
          check=0;
          break;
        } else tempAnswer += result;
      }

      if(check) answer = std::min(answer, tempAnswer); // 완주 했으면 답에 추가
    } while(std::next_permutation(dirtySpaces.begin(), dirtySpaces.end(), compairFunc));

    // 출력
    answer == INT_MAX ? std::cout << -1 << "\n" : std::cout << answer << "\n";
  }
  return 0;
}