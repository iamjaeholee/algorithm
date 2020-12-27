#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[10000];
int answer = 1 << 10;
int N, D;

void dfs(int current, int distance) {
  if(current == D){
    answer = min(answer, distance);
    return;
  }

  for(auto i: v[current]){
    dfs(i.first, distance+i.second); // jump over
  }

  dfs(current+1, distance+1); // move forward
}

int main() {
  cin >> N >> D;
  while(N--){
    int s, e, d;
    cin >> s >> e >> d;
    if(e <= D) v[s].push_back({e, d}); // filter unvalid value
  }

  dfs(0, 0);

  cout << answer;

  return 0;
}