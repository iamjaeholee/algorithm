#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>

int find(int node, std::vector<int>& nodes) {
  if(nodes[node] == node) return node;
  else return find(nodes[node], nodes);
}

bool union_find(int u, int v, std::vector<int>& nodes) {
  int U=find(u, nodes);
  int V=find(v, nodes);
  if(U == V) return false;
  else {
    nodes[V] = U;
    return true;
  }
}

int main(){
  int N, P;
  std::cin >> N >> P;
  std::vector<int> country;
  std::vector<std::tuple<int, int, int>> edges;
  std::vector<int> nodes;
  nodes.push_back(0); // 0 index
  country.push_back(0); // 0 index
  
  int entry_point=INT_MAX;
  for(int i=0; i<N; i++) {
    int temp;
    std::cin >>  temp;
    nodes.push_back(i+1);
    country.push_back(temp);
    entry_point=std::min(entry_point, temp);
  }

  for(int i=0; i<P; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    w += w + country[u] + country[v];
    edges.push_back(std::make_tuple(u, v, w));
  }

  std::sort(edges.begin(), edges.end(), [](std::tuple<int, int, int>f, std::tuple<int, int, int>s){
    if(std::get<2>(f) < std::get<2>(s)) return 1;
    else return 0;
  });

  int answer=0;
  for(int i=0; i<P; i++) {
    int u, v, w;
    std::tie(u, v, w) = edges[i];
    if(union_find(u, v, nodes)) answer+=w;
  }

  std::cout << answer + entry_point;

  return 0;
}