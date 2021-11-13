#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_CITY{10001};
vector<pair<int, int>> pasture[MAX_CITY];
int N, M, K;

int dfs(vector<int> visited, int k, int node){
  int result = 65532;

  if(node == N) return 0;

  for(auto i=0; i<int(pasture[node].size()); i++){
    int nextNode = pasture[node][i].first;
    int weight = pasture[node][i].second;

    if(find(visited.begin(), visited.end(), nextNode) == visited.end()) {

      visited.push_back(node);
      int tem;
      tem = weight + dfs(visited, k, nextNode);
      if(k != 0) {
        int tem2;
        tem2 = dfs(visited, k-1, nextNode);
        tem = min(tem2, tem);
      } 
      result = min(result, tem);
    }
  }

  return result;
}

int main() {
  cin >> N >> M >> K;
  for(auto i=0; i<M; i++){
    int u, v, k;
    cin >> u >> v >> k;

    pasture[u].push_back({v, k});
    pasture[v].push_back({u, k});
  }

  vector<int> visited;
  cout << dfs(visited, K, 1);

  return 0;
}
