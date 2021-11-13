#include <iostream>
#include <vector>

using namespace std;

int N, garbage;
const int MAX=1000001;
int visit[MAX];
vector<int> graph[MAX];
vector<int> memo[MAX];

int dp(int cur, int adaptor){
  if(memo[cur][adaptor] != garbage) return memo[cur][adaptor];

  visit[cur] = 1;
  if(adaptor) memo[cur][adaptor] = 1;
  else memo[cur][adaptor] = 0;

  for(auto next: graph[cur]){
    if(!visit[next]){
      if(adaptor) memo[cur][adaptor] += min(dp(next, 1), dp(next, 0));
      else memo[cur][adaptor] += dp(next,1);
    }
  }

  visit[cur] = 0;
  
  return memo[cur][adaptor];
}

int main(){
  int f, s;

  cin >> N;

  for(auto i=0; i<N - 1; i++){
    cin >> f >> s;
    graph[f].push_back(s);
    graph[s].push_back(f);
  }

  garbage = 1 << 19;
  for(auto i=1; i<=N; i++){
    memo[i].assign(2, garbage);
  }

  cout << min(dp(1, 1), dp(1,0)) << endl;
  return 0;
}
