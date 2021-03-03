#include <iostream>
#include <vector>
#include <climits>

int tempCount=INT_MAX;

void dfs(int cur, int des, std::vector<std::vector<std::pair<int, int>>>& v, std::vector<int>& checker, int sum){
  if(cur==des) {
    tempCount=std::min(tempCount, sum);
    return;
  }

  else {
    checker[cur]=1;
    for(int i=0; i<v[cur].size(); i++){
      if(checker[v[cur][i].first] == 0) dfs(v[cur][i].first, des, v, checker, sum+v[cur][i].second);
    }
  }

  return;
}

int main(){
  while(true) {
    int n;
    std::cin >> n;
    if(n==0) break;

    std::vector<std::vector<std::pair<int, int>>> v;
    for(int i=0; i<n; i++){
      std::vector<std::pair<int, int>> t;
      v.push_back(t);
    }

    for(int i=0; i<n-1; i++){
      int a, b, w;
      std::cin >> a >> b >> w;
      v[a].push_back({b, w});
      v[b].push_back({a, w});
    }

    int ans=INT_MAX;
    for(int i=0; i<n; i++){
      int sum=0;

      for(int j=0; j<n; j++){ // search node weight
        if(j==i) continue;
        std::vector<int> checker;
        checker.assign(n, 0);
        tempCount=INT_MAX;
        dfs(i, j, v, checker, 0);
        sum+=tempCount;
      }

      ans=std::min(ans, sum);
    }


    std::cout << ans << std::endl;
  }

  return 0;
}