#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;

vector<pair<int, int>> v[100001];
int n, m, s, e, h1, h2, k;

bool bfs(int mid) {
  bool check[n + 1];
  memset(check, false, sizeof(check));
  queue<int> q;

  q.push(s);
  check[s] = true;

  while(!q.empty()) {
    int c = q.front();
    q.pop();
    
    if(c == e) return true;

    for(auto nxt : v[c]) {
      int next = nxt.first;
      int value = nxt.second;

      if(check[next]) continue;

      if(value >= mid) {
        q.push(next);
        check[next] = true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  // input
  cin >> n >> m >> s >> e;

  while(m--){
    cin >> h1 >> h2 >> k;
    v[h1].push_back(make_pair(h2, k));
    v[h2].push_back(make_pair(h1, k));
  }

  // bfs
  int l=1;
  int r=1e7;
  int result=0;

  while(l <= r) {
    m = (l + r)/2;

    if(bfs(m)) {
      result = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  cout << result;

  return 0;
}
