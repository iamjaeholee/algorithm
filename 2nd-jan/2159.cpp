#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;
int N, X, Y;
int answer = INT_MAX;
const int MAX = 100000;
int direction[5]{1, -1, 0, 0, 0};

void dp(pair<int, int> cur, vector<pair<int, int>>& v, int index, int sum) {
  if(v.size() == index) {
    answer = min(answer, sum);
    return; // end of the dp
  }

  map<pair<int,int>, int> m;
  pair<int, int> next = v[index]; //next node
  int minimum{1 << 13};
  for(int i=0; i<5; i++){
    pair<int, int> temp{next.first+direction[i], next.second+direction[4-i]};
    if(temp.first > MAX || temp.first < 0 || temp.second > MAX || temp.second < 0) continue; // check possibility
    int distance = abs(temp.first-cur.first) + abs(temp.second-cur.second);
    minimum = min(distance, minimum);
    m[temp] = distance;
  }

  for (auto const& e : m){
    if(e.second == minimum) {
      dp(e.first, v, index+1, sum+e.second);
    }
  }

  return;
}

int main() {
  cin >> N >> X >> Y;
  vector<pair<int, int>> v;

  for(int i=0; i<N; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  dp({X, Y}, v, 0, 0);

  if(answer == INT_MAX) {
    cout << 0;
  } else {
    cout << answer;
  }
  return 0;
}