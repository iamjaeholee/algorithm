#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 200001;
vector<int> tree[MAX];
int quality[MAX], memo[MAX][2];

int dfs(int node, int isMentor) {
  if(tree[node].size() == 0) return 0; // return if could not be mentor
  if(memo[node][isMentor] != -1) return memo[node][isMentor];

  int sum=0;
  for(auto next: tree[node]) sum+=dfs(next, 1);

  int result=sum;

  if(isMentor) {
    for(auto next: tree[node]) {
      result = max(result, sum - dfs(next,1) + dfs(next, 0) + quality[node] * quality[next]); // find max value;
    }
  }

  memo[node][isMentor] = result;
  return result;
}

int main() {
  int N;
  cin >> N;

  for(int i=2; i<=N; i++) {
    int mentor;
    cin >> mentor;
    tree[mentor].push_back(i);
  }

  for(int i=1; i<=N; i++) {
    cin >> quality[i];
  }

  memset(memo, -1, sizeof(memo));
  cout << dfs(1, 1);

  return 0;
}