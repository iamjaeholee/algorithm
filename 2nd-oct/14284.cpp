#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 5001;

int N, M;
vector<pair<int, int>> v[MAX];
int visit[MAX];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

int main(){
  cin >> N >> M;
  
  int a, b, c;
  while(M--){
    cin >> a >> b >> c;
    v[a].push_back({c, b});
    v[b].push_back({c, a});
  }

  int s, t;
  cin >> s >> t;

  q.push({0, s});

  memset(visit, 0, sizeof visit);
  while(!q.empty()){
    pair<int, int> temp = q.top();
    q.pop();
    visit[temp.second] = 1;

    if(temp.second == t) {
      cout << temp.first;
      break;
    }

    for(pair<int, int> next: v[temp.second]) if(!visit[next.second]) q.push({temp.first + next.first, next.second});
  }
  
  return 0;
}
