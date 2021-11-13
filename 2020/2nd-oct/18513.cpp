#include <iostream>
#include <set>
#include <queue>

using namespace std;

int N, K;
long long answer;
queue<pair<int, int>> q;
set<int> check;

void bfs(){
  while(!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();

    for(auto i=-1; i<=1; i++){
      if(i) {
        int next = cur.first + i;
        if(next < -100000000 || next > 100000000 || check.count(next) != 0) continue;

        q.push({next, cur.second + 1});
        answer += cur.second;
        K--;
        if(K==0) return;
        check.insert(next);
      }
    }
  }
}

int main(){
  cin >> N >> K;

  while(N--){
    int temp;
    cin >> temp;

    q.push({temp, 1});
    check.insert(temp);
  }

  answer = 0;
  bfs();

  cout << answer;

  return 0;
}
