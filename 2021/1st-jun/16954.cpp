#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define vs std::vector<std::string>
#define vvi std::vector<std::vector<int>>
#define pii std::pair<int, int>

pii directions[8]{{1, 0},{-1, 0},{1, 1},{-1, 1},{0, 1},{0, -1},{1, -1},{-1, -1}};
int N=8;

struct Node{
  int row;
  int col;
  int time;
};

vs makeTempMap(const vs& map, const int& time){
  int level = time > N ? N : time;
  std::string temp = "........";
  vs tempMap(level, temp);
  
  for(int i=0; i<N-level; i++){
    tempMap.push_back(map[i]);
  }

  return tempMap;
}

bool isPossible(const vs& map, vvi& checker, const Node& node, const pii& direction){
  int row = node.row + direction.first;
  int col = node.col + direction.second;

  if(row >=0 && row <N && col >= 0 && col <N){
    vs tempMap = makeTempMap(map, node.time);

    if(tempMap[row][col] == '.'){
      if(checker[row][col] == 0) return true;
    }
  }

  return false;
}

bool isContinuosible(const vs& map, const Node& node){
  vs tempMap = makeTempMap(map, node.time);

  int row = node.row;
  int col = node.col;

  if(tempMap[row][col] == '#') return false;
  return true;
}

bool isEnd(const Node& node){
  return node.row == 0 && node.col == N-1 ? true : false;
}

bool bfs(vs& map, vvi& checker) {
  std::queue<Node> q;

  Node cur = {N-1, 0, 0};
  checker[cur.row][cur.col] = 1; // check
  q.push(cur); // push

  while(!q.empty()){
    cur = q.front();
    q.pop();

    if(!isContinuosible(map, cur)) continue; // check continuos ability
    if(isEnd(cur)) return true; // end condition

    for(auto direction: directions){
      if(isPossible(map, checker, cur, direction)){ // check possibility
        int row = cur.row + direction.first;
        int col = cur.col + direction.second;

        Node next = {row, col, cur.time+1};
        checker[row][col] = 1;
        q.push(next);
      }
    }

    Node next = {cur.row, cur.col, cur.time+2}; // standing
    q.push(next);
  }

  return false;
}

int main(){
  vs map(N);

  for(int i=0; i<N; i++){
    std::getline(std::cin, map[i]);
  } // input

  std::vector<int> temp(N, 0); vvi checker(N, temp);

  std::cout << bfs(map, checker) ? 1 : 0;


  return 0;
}