#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

struct Edge {
  int from;
  int to;
  int weight;
};

bool ascending(const Edge& a, const Edge& b){
  return a.weight < b.weight ? true : false;
}
bool descending(const Edge& a, const Edge& b){
  return a.weight > b.weight ? true : false;
}

int find(std::vector<int>& trees, const int& node){
  if(trees[node] == node) return node;
  else return trees[node] = find(trees, trees[node]);
}

bool unionNodes(std::vector<int>& trees, const int& x, const int& y){
  int rootX = find(trees, x);
  int rootY = find(trees, y);

  if(rootX == rootY) return false;
  else {
    trees[rootY] = rootX;
    return true;
  }
}

int getKruscal(std::vector<Edge>& edges, const int& M, std::vector<int> trees, const int& toggle){
  toggle ? std::sort(edges.begin(), edges.end(), descending) : std::sort(edges.begin(), edges.end(), ascending);

  int answer = 0, count=0;
  for(auto edge: edges){
    if(unionNodes(trees, edge.from, edge.to)){
      answer += edge.weight;
      count++;
    }

    if(count == M-2) break;
  }

  return answer;
}

void setTrees(std::vector<int>& trees, const int& M){
  for(int i=0; i<=M; i++) trees[i] = i;
  unionNodes(trees, 0, 1);
}

int main(){
  int N, M;
  std::cin >> N >> M;
  std::vector<Edge> edges(M);

  Edge entrance;
  std::cin >> entrance.from >> entrance.to >> entrance.weight; // 입구 데이터

  for(int i=0; i<M; i++) std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;

  std::vector<int> trees(M+1, M);
  setTrees(trees, M);

  int answer = pow(entrance.weight + getKruscal(edges, M, trees, 1), 2)  - pow(entrance.weight + getKruscal(edges, M, trees, 0), 2); // 가장 큰 값에서 가장 작은 값 빼기
  std::cout << answer;

  return 0;
}