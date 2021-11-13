#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>

int bfs(std::vector<std::string>& map, std::tuple<std::pair<int, int>, std::pair<int, int>, int>& node, const int& N, const int& M){
  std::pair<int, int> directions[4]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::queue<std::tuple<std::pair<int, int>, std::pair<int, int>, int>> q;
  q.push(node);

  while(!q.empty()){
    std::tuple<std::pair<int, int>, std::pair<int, int>, int> cur = q.front();
    q.pop();

    for(auto direction: directions){
      std::pair<int, int> firstCoin, secondCoin, nextFirstCoin, nextSecondCoin; int count;
      std::tie (firstCoin, secondCoin, count) = cur; // 언팩하기
      nextFirstCoin = {firstCoin.first + direction.first, firstCoin.second + direction.second}; // 새로운 코인 위치 정하기
      nextSecondCoin = {secondCoin.first + direction.first, secondCoin.second + direction.second}; // 새로운 코인 위치 정하기

      int firstStatus=1, secondStatus=1;
      if(nextFirstCoin.first >= N || nextFirstCoin.first < 0 || nextFirstCoin.second >= M || nextFirstCoin.second < 0) firstStatus = 0;
      if(nextSecondCoin.first >= N || nextSecondCoin.first < 0 || nextSecondCoin.second >= M || nextSecondCoin.second < 0) secondStatus = 0;

      if(count == 10) return -1; // 10번보다 많이 ? 종료
      if(firstStatus == 0 && secondStatus == 0) continue; // 둘 다 떨어질 땐 패스
      if(firstStatus != secondStatus) return count + 1; // 하나만 떨어지면 답
      if(map[nextFirstCoin.first][nextFirstCoin.second] == '#' && map[nextSecondCoin.first][nextSecondCoin.second] == '#') continue; // 둘 다 벽일 땐 패스
      if(map[nextFirstCoin.first][nextFirstCoin.second] == '#') nextFirstCoin = firstCoin; // 하나만 벽일 땐 푸쉬
      if(map[nextSecondCoin.first][nextSecondCoin.second] == '#') nextSecondCoin = secondCoin; // 하나만 벽일 땐 푸쉬

      q.push({nextFirstCoin, nextSecondCoin, count+1}); // 갈 수 있는 길이면 푸쉬
    }
  }

  return -1;
}

void findCoin(std::vector<std::string>& map, std::tuple<std::pair<int, int>, std::pair<int, int>, int>& node, const int& N, const int& M){
  std::vector<std::pair<int, int>> coins;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(map[i][j] == 'o') coins.push_back({i, j});
    }
  }

  node = {coins[0], coins[1], 0};
}

int main(){
  int N, M;
  std::cin >> N >> M;
  std::cin.ignore();
  std::vector<std::string> map(N);

  for(int i=0; i<N; i++) std::getline(std::cin, map[i]);

  std::tuple<std::pair<int, int>, std::pair<int, int>, int> node{{0, 0}, {0,0}, 0};
  findCoin(map, node, N, M);

  std::cout << bfs(map, node, N, M);

  return 0;
}