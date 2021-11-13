#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& graph, std::vector<int>& checker, const int& node){
  checker[node] = 1;

  for(auto nextNode: graph[node]) if(checker[nextNode] == 0) dfs(graph, checker, nextNode);
}

int main(){
  int N;
  std::cin >> N;
  std::vector<std::vector<int>> graph(N+1);

  for(int i=0; i<N-2; i++){
    int from, to;
    std::cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  std::vector<int> checker(N+1, 0);
  dfs(graph, checker, 1);

  for(int i=2; i<=N; i++){
    if(checker[i] == 0) {
      std::cout << 1 << " " << i;
      break;
    }
  }

  return 0;
}