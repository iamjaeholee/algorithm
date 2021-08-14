#include <iostream>
#include <vector>

int main(){
  std::vector<std::pair<int, int>> v;

  while(true){
    int u, v;
    std::cin >> u >> v;

    if(u == -1 && v == -1) break; // finish line

    if(u == 0 && v == 0) {
      findRoot();
      dfs();
    }

  }

  return 0;
}