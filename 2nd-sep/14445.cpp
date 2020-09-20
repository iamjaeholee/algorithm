#include <iostream>
#include <vector>

using namespace std;

int N,M;
char map[50][50];
pair<int, int> S, F;
vector<pair<int, int>> results;

void garbageChecker(pair<int,int> location, pair<int, int>& garbage){
  pair<int, int> directions[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  if(map[location.first][location.second] == 'g') garbage.first++;
  else {
    for(auto i=0; i<4; i++) {
      int x = location.first+directions[i].first;
      int y = location.second+directions[i].second;

      if(x >= 0 && x < N && y >=0 && y < M) if(map[x][y] == 'g') garbage.second++;
    }
  }
}

void run(pair<int, int> s, pair<int, int> garbage){
  cout << "debug:" << s.first << " " << s.second << "\n";

  if(s == F) results.push_back(garbage);
  else {
    if(s != S) garbageChecker(s, garbage);
    int x = F.first - s.first;
    int y = F.second - s.second;

    if(x > 0) run(make_pair(s.first+1, s.second), garbage);
    if(x < 0) run(make_pair(s.first-1, s.second), garbage);
    if(y > 0) run(make_pair(s.first, s.second+1), garbage);
    if(y < 0) run(make_pair(s.first, s.second-1), garbage);
  }
}

int main() {
  cin >> N >> M;
  
  for(auto i=0; i<N; i++){
    for(auto j=0; j<M; j++){
      cin >> map[i][j];
      if(map[i][j] == 'S') S = make_pair(i, j);
      if(map[i][j] == 'F') F = make_pair(i, j);
    }
  }

  run(S, make_pair(0, 0));

  for(auto i=0; i < results.size(); i++){
    cout << results[i].first << " " << results[i].second << "\n";
  }

  return 0;
}
