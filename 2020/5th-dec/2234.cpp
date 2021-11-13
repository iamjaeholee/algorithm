#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int X, Y;
int map[50][50];
int checker[50][50];
queue<pair<int, int>> q;
pair<int, int> directions[4]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int district = 0;
vector<int> roomSize{0};
int maximumRoomSize = 0;

void bfs(pair<int, int> node) {
  district++; // room checker
  checker[node.first][node.second] = district;
  q.push(node);
  roomSize.push_back(1); // initializing roomSize of this district

  while(!q.empty()) {
    pair<int, int> cNode = q.front();
    q.pop();

    for(auto i=0; i<4; i++){
      if( ( map[cNode.first][cNode.second] & (1<<(3-i)) ) == 0 ) { // if no walls
        pair<int, int> nNode = {cNode.first + directions[i].first, cNode.second + directions[i].second};
        if(!checker[nNode.first][nNode.second] && nNode.first >=0 && nNode.first < Y && nNode.second >=0 && nNode.second < X) {
          q.push(nNode);
          roomSize[district] = roomSize[district]+1; // increase room size
          checker[nNode.first][nNode.second] = district;
        }
      }
    }
  }
}

int main(){
  memset(map, -1, sizeof map);
  memset(checker, 0, sizeof checker);

  cin >> X >> Y;
  for(auto i=0; i<Y; i++) {
    for(auto j=0; j<X; j++) {
      cin >> map[i][j];
    }
  }

  for(auto y=0; y<Y; y++){
    for(auto x=0; x<X; x++){
      if(!checker[y][x]) {
        bfs({y, x});
      }
    }
  }
  // calculate maximum roomSize
  for(auto y=0; y<Y; y++){
    for(auto x=0; x<X; x++){
      for(auto i=0; i<4; i++){
        if( ( map[y][x] & (1<<(3-i)) ) > 0 ) { // if walls
          pair<int, int> nNode = {y + directions[i].first, x + directions[i].second};
          if( checker[y][x] != checker[nNode.first][nNode.second]){
            if(nNode.first >=0 && nNode.first < Y && nNode.second >=0 && nNode.second < X) {
              maximumRoomSize = max(maximumRoomSize, roomSize[checker[y][x]] + roomSize[checker[nNode.first][nNode.second]]);
            }
          }
        }
      }
    }
  }

  sort(roomSize.begin(), roomSize.end(), greater<int>());
  cout << district << endl;
  cout << roomSize[0] << endl;
  cout << maximumRoomSize << endl;

  return 0;
}