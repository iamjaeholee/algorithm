#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main(){
  int N, ans=INT_MAX;
  std::vector<int> v;
  std::cin >> N;
  for(int i=0; i<N; i++) {
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      int first = v[i] + v[j];

      int a=i;
      int b=N-1;

      while(true){
        while(a == i || a == j) a++;
        while(b == i || b == j) b--;

        if(a >= b) break;

        int second = v[a] + v[b];
        if(first < second) {
          ans = std::min(ans, second-first);
          b--;
        } else if(first >= second) {
          ans = std::min(ans, first-second);
          a++;
        }
      }
    }
  }

  std::cout << ans;

  return 0;
}