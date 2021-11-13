#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(){
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> v;

  int max_day=0;
  for(int i=0; i<N; i++){
    int p, d;
    std::cin >> p >> d;

    v.push_back({-d, p});
    max_day=std::max(max_day, d);
  } 

  sort(v.begin(), v.end());

  int index=0, answer=0;
  std::priority_queue<int> pq;

  for(int day=max_day; day >= 1; day--){
    while(index < N && -v[index].first >= day){
      pq.push(v[index].second);
      index++;
    }

    if(!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
  }

  std::cout << answer;

  return 0;

}