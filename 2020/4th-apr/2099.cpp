#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

void check(const int& a, const int& b, std::vector<std::set<int>> const & graph, const int& K){
  std::deque<int> q;

  q.push_back(a);

  int k=0;
  while(k != K){
    int size = q.size();
    for(int i=0; i<size; i++){
      int node = q.front();
      q.pop_front();

      for(auto element: graph[node]){
        q.push_back(element);
      }
    }

    k++;
  }

  std::find(q.begin(), q.end(), b) != q.end() ? std::cout << "death\n" : std::cout << "life\n";
}

int main(){
  int N, K, M;

  std::cin >> N >> K >> M;

  std::vector<std::set<int>> graph(N+1);

  for(int i=1; i<=N; i++){
    int temp; std::cin >> temp;
    graph[i].insert(temp);
    std::cin >> temp;
    graph[i].insert(temp);
  }

  std::vector<std::pair<int, int>> m;
  for(int i=0; i<M; i++){
    int a, b; std::cin >> a >> b;
    m.push_back({a, b});
  }

  for(auto element: m){
    check(element.first, element.second, graph, K);
  }

  return 0;
}