#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
  int N, K;
  deque<int> s;
  vector<int> v;
  cin >> N >> K;

  for(auto i=0; i<2*N; i++){
    int temp; cin >> temp;
    v.push_back(temp);
  }

  int answer=0;
  int index=0;
  while(K > 0) {
    answer++;
    index--; //rotate
    if(index == -1) index = N-1;

    int prevRobot = -1;
    for(auto i=0; i<s.size(); i++){
      int nextIndex = s[i] + 1;
      int nextCount = (nextIndex + index) % N;
      if(nextIndex == N-1 && v[nextCount] > 0) { // go down
        s.pop_front();
        v[nextCount] -= 1;
        prevRobot = -1; 
      } else if(nextIndex != prevRobot && v[nextCount] > 0) {
        s[i] = nextIndex; //move
        v[nextCount] -= 1;
        prevRobot = s[i];
      } else {
        prevRobot = s[i];
      }

      if(v[nextCount] == 0) K--;
    }

    if(prevRobot != 0) {
      v[index]--;
      if(v[index] == 0) K--;
      s.push_back(0); //go up
    }

  }

  cout << answer;

  return 0;
}