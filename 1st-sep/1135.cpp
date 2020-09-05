#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 50;
int workers[MAX]; // worker's master information
vector<int> ch[MAX]; // worker's childs information

int dfs(int worker){
  int size = ch[worker].size();
  vector<int> time; // child's spend time

  // if leaf tree return 0
  if(size == 0) return 0;

  for(auto i=0; i<size; i++){
    time.push_back(dfs(ch[worker][i]));
  }

  sort(time.begin(), time.end(), greater<int>());

  // find maximum time to spend
  int max=0;
  for(auto i=0; i<(int)time.size(); i++){
    if(max < time[i] + i+1) max = time[i] + i + 1;
  }

  return max;
}

int main() {
  int n;
  cin >> n;

  for(auto i=0; i<n; i++){
    int master;
    cin >> master;
    workers[i] = master;

    if(master != -1) {
      ch[master].push_back(i);
    }
  }

  cout << dfs(0);

  return 0;
}
