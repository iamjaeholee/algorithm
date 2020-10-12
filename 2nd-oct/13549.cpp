#include <iostream>

using namespace std;

int N, K, answer;

void dp(int time, int current){
  if(current == K) {
    cout << time << endl;
    if(answer > time) answer = time;
    return;
  }

  if(current-1 >= 0 && current > K) dp(time+1, current-1);
  if(current+1 <= 100000 && current < K) dp(time+1, current+1);
  if(current*2 <= 100000 && current < K) dp(time, current*2);
  return;
}

int main() {
  cin >> N >> K;
  answer = 1 << 19;
  dp(0, N);

  cout << answer;
  return 0;
}
