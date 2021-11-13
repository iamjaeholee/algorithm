#include <iostream>
#include <vector>
#include <map>
#include <tuple>

int N;
std::vector<int> v;
std::map<std::tuple<int, int, int>, int> m;

int dp(int i, int combo, int k) {
  std::tuple<int, int, int> t = std::make_tuple(i, combo, k);

  if(i == N-1) { // return when index is final
    m[t] = v[i]*combo; // memo
  } else { // dp to last index
    if(m.find(t) == m.end()) {
      if(k < 2) {
        m[t] = std::max(v[i]*combo + dp(i+1, combo+1, 0), v[i]*combo + dp(i+1, 0, k+1));
      } else {
        m[t] = v[i]*combo + dp(i+1, combo+1, 0);
      }
    }
  }

  return m[std::make_tuple(i, combo, k)];
}


int main() {
  std::cin >> N;
  for(int i=0; i<N; i++) {
    int temp; std::cin >> temp;
    v.push_back(temp);
  }

  int answer = std::max(dp(0, 1, 0), dp(0, 0, 1));
  std:: cout << std::max(answer, 0);

  return 0;
}