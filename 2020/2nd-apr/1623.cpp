#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

// 6
// -10 5 20 15 -5 10
// 1 1 2 2 1

int dfs(int node, int isSelected, int (*cache)[2], std::vector<int>* graph, std::vector<int>& cost){
  int& ret = cache[node][isSelected];
  if(ret != -1) return ret;

  ret = isSelected ? cost[node] : 0;
  for(auto i : graph[node]){
    if(isSelected) ret += dfs(i, 0, cache, graph, cost);
    else ret += std::max(dfs(i, 0, cache, graph, cost), dfs(i, 1, cache, graph, cost));
  }

  return ret;
}

void backtracking(int node, int isSelected, int (*cache)[2], std::vector<int>* graph, std::vector<int>& result){
  if(isSelected) result.push_back(node);

  for(auto i : graph[node]){
    if(isSelected) backtracking(i, 0, cache, graph, result);
    else backtracking(i, cache[i][0] < cache[i][1], cache, graph, result);
  }
}

int main(){
  int N;
  std::cin >> N;
  std::vector<int> cost(N+1);
  std::vector<int> graph[200001];
  int cache[200001][2];

  for(int i=1; i<=N; i++) std::cin >> cost[i];
  for(int i=2; i<=N; i++) {
    int temp;
    std::cin >> temp;
    graph[temp].push_back(i);
  }

  memset(cache, -1, sizeof cache);

  std::vector<int> result;
  std::cout << dfs(1, 1, cache, graph, cost) << " " << dfs(1, 0, cache, graph, cost) << "\n";
  backtracking(1, 1, cache, graph, result);
  std::sort(result.begin(), result.end());
  for(auto i : result) std::cout<<i<< " ";
  std::cout << -1 << "\n";
  result.clear();

  backtracking(1, 0, cache, graph, result);
  std::sort(result.begin(), result.end());
  for(auto i : result) std::cout<<i<< " ";
  std::cout << -1 << "\n";

  return 0;
}