#include <iostream>
#include <vector>
#include <climits>

#define pii std::pair<int, int>

void dfs(std::vector<std::vector<pii>>& graph, std::vector<int>& checker, const int& from, const int& B, const int& C, int sum, int& answer, int max){
  if(from == B){
    if(sum <= C){
      answer = std::min(answer, max);
    }

    return;
  } else checker[from] = 1;

  for(auto node: graph[from]){
    int to = node.first, weight = node.second;
    
    if(checker[to] == 0) {
      dfs(graph, checker, to, B, C, sum+weight, answer, std::max(max, weight));
    }
  }

  return;
}

int main(){
  int N, M, A, B, C;
  std::cin >> N >> M >> A >> B >> C;
  std::vector<std::vector<pii>> graph(N + 1);

  for(int i=0; i<M; i++){
    int from, to, weight;
    std::cin >> from >> to >> weight;
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
  }

  int answer=INT_MAX, sum=0, max=0;

  std::vector<int> checker(N+1, 0);
  dfs(graph, checker, A, B, C, sum, answer, max);
  
  answer == INT_MAX ? std::cout << -1 : std::cout << answer;

  return 0;
}