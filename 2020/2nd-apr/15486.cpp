#include <iostream>
#include <vector>

int N;

int dp(int day, std::vector<std::pair<int, int>>& v, std::vector<int>& memo){
  if(day == N+1) return 0; // finish line

  int& price = memo[day];
  if(price != -1) return price; // if have memo return

  price = 0;

  int nextDay = day + v[day].first;
  if(nextDay <= N+1) {
    price = std::max(v[day].second + dp(nextDay, v, memo), price + dp(day+1, v, memo));
  }
  else {
    price += dp(day+1, v, memo);
  }

  return price;
}

int main(){
  std::cin >> N;
  std::vector<std::pair<int, int>> v(N+1);
  std::vector<int> memo(N+1, -1);

  for(int i=1; i<=N; i++){
    int t, p;
    std::cin  >> t >> p;
    v[i] = {t, p};
  }

  std::cout << dp(1, v, memo);


  return 0;
}