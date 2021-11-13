#include <iostream>
#include <vector>
#include <tuple>

int answer=0; int city=0;
int n, m, start, destination;

void dfs(std::vector<std::tuple<int, int, int>> &v, int cur, int weight, int cityNumber){
  if(cur == destination) { //terminate
    answer = std::max(answer, weight);
    city = std::max(city, cityNumber);
    return;
  }

  for(int i=0; i<m; i++) {
    int s, d, w;
    std::tie(s, d, w) = v[i];

    if(s == cur) dfs(v, d, weight+w, cityNumber+1);
  }

  return;
}

int main(){
  std::cin >> n >> m;
  std::vector<std::tuple<int, int, int>> v;

  for(int i=0; i<m; i++) {
    int s, d, w;
    std::cin >> s >> d >> w;
    v.push_back({s, d, w});
  }

  std::cin >> start >> destination;

  dfs(v, start, 0, 1);

  std::cout << answer << "\n" << city;

  return 0;
}