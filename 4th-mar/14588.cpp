#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(int n, std::pair<int, int> const& p){
    return p.first < n;
}

int main(){
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> v;

  for(int i=0; i<N; i++){
    int l, r;
    std::cin >> l >> r;
    v.push_back({l, r});
  }

  int Q;
  std:: cin >> Q;
  for(int i=0; i<Q; i++){
    int a, b;
    std::cin >> a >> b;

    std::pair<int, int> l1, l2;

    if(v[a-1].first <= v[b-1].first){
      l1 = v[a-1];
      l2 = v[b-1];
    } else {
      l1 = v[b-1];
      l2 = v[a-1];
    }

    if(l1.second >= l2.first){ // if connected
      std::cout << 1;
      continue;
    }

    std::vector<std::pair<int, int>> sorted; 
    sorted.assign(v.begin(), v.end());
    sort(sorted.begin(), sorted.end());
    int count=1;

    while(true){
      std::vector<std::pair<int, int>> partial;
      partial.assign(std::lower_bound(sorted.begin(), sorted.end(), l1.first, cmp), std::upper_bound(sorted.begin(), sorted.end(), l1.second, cmp));
    //   if(partial.size() == 0){ // there is no answer
    //     std::cout << -1;
    //     break;
    //   }

    //   sort(partial.begin(), partial.end(), [](const std::pair<int, int> a, const std::pair<int, int> b){return a.second >= b.second;}); // sort by second 
    //   if(partial[0].second <= l1.second){ // there is no answer
    //     std::cout << -1;
    //     break;
    //   }

    //   l1 = partial[0];
    //   count++;

    //   if(l1.second >= l2.first){ // if connected
    //     std::cout << count;
    //     break;
    //   }
    }
  }

  return 0;
}