#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> v, result;

  for(int i=0; i<N; i++) {
    int n, x, y;
    std::cin >> n >> x >> y;
    v.push_back({-x, y});
  } 

  sort(v.begin(), v.end());
  // sort(v.begin(), v.end(), [](std::pair<int, int>i, std::pair<int, int>j){
  //   if(i.first == j.first) return i.second < j.second;
  //   return i.first > j.first;
  // });

  for(int i=0; i<N; i++) {
    result.push_back(std::make_pair(INT_MAX, INT_MAX));
    std::pair<int, int> swaped{v[i].second, v[i].first};
    *std::lower_bound(result.begin(), result.end(), swaped) = swaped;
  }

  std::pair<int, int> inf = {INT_MAX, INT_MAX};
  std::cout << std::lower_bound(result.begin(), result.end(), inf) - result.begin();
}