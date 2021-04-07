#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int whereIsRoot(int N, std::vector<std::pair<int, int>>& tree){
  int root= N * (N+1)/2;
  for(int i=1; i<=N; i++){
    int left = tree[i].first;
    int right = tree[i].second;

    if(left != -1) root-=left;
    if(right != -1) root-=right;
  }

  return root;
}

int calcX(std::vector<std::pair<int, int>>& tree, int node, std::vector<int>& column, int prevWidth, int level, std::vector<int>* levels){
  levels[level].push_back(node); // push node to levels

  int width = prevWidth;
  int left = tree[node].first;
  int right = tree[node].second;

  if(left != -1) {
    width = calcX(tree, left, column, width, level+1, levels);
  }

  width = width + 1;
  column[node]=width;

  if(right != -1) width = calcX(tree, right, column, column[node], level+1, levels);

  return width;
}

int main(){
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> tree;

  tree.assign(N+1, {0, 0});

  for(int i=0; i<N; i++){
    int root, left, right;
    std::cin >> root >> left >> right;
    tree[root] = {left, right};
  }

  std::pair<int, int> answer = {1, 1}; // answer

  int root = whereIsRoot(N, tree); // checkRoot

  std::vector<int> column(N+1);
  std::vector<int> levels[N+1];
  calcX(tree, root, column, 0, 1, levels);


  for(int i=1; i<=N; i++){
    int nodeSize = levels[i].size();
    int biggest=0;
    int smallest=INT_MAX;
    if(nodeSize == 1) continue;

    else {
      for(int j=0; j<nodeSize; j++){
        int colSize = column[levels[i][j]];
        biggest = std::max(biggest, colSize);
        smallest = std::min(smallest, colSize);
      }

      if(answer.second < (biggest - smallest + 1)){
        answer.second = (biggest - smallest + 1);
        answer.first = i;
      }
    }
  }

  std::cout << answer.first << " " << answer.second;

  return 0;
}