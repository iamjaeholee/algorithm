#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main() {
  int N, X, Y;
  long long answer = LLONG_MAX;
  int direction[5]{1, -1, 0, 0, 0};
  long long dp[2][5];

  cin >> N >> X >> Y;
  for(int i=0; i<2; i++){
    for(int j=0; j<5; j++){
      if(i==0) dp[i][j] = abs(direction[j] + direction[4-j]);
      else dp[i][j] = LLONG_MAX;
    }
  }

  for(int i=1; i<=N; i++) {
    int x, y;
    cin >> x >> y;

    for(int j=0; j<5; j++) { // prev
      for(int k=0; k<5; k++) { // next
        long long distance = abs(X+direction[j]-(x+direction[k])) + abs(Y+direction[4-j]-(y+direction[4-k]));
        dp[i%2][k] = min(dp[i%2][k], dp[(i+1)%2][j] + distance);
      }
    }

    for(int j=0; j<5; j++) dp[(i+1)%2][j] = LLONG_MAX;

    X = x; Y= y;
  }

  for(int i=0; i<5; i++) {
    answer = min(answer, dp[N%2][i]);
  }

  cout << answer;

  return 0;
}