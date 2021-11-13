#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
pair<int, int> checker;
vector<int> starx, stary;
vector<int> x, y;

int check(int inc, vector<int>& a, vector<int>& b){
  for(int i=0; i<a.size(); i++){
    if(b.end() != find(b.begin(), b.end(), a[i] + inc)) continue;
    return 0;
  }

  return 1;
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    int tx, ty; cin >> tx >> ty;
    
    if(starx.end() == find(starx.begin(), starx.end(), tx)) starx.push_back(tx);
    if(stary.end() == find(stary.begin(), stary.end(), ty)) stary.push_back(ty);
  }
  
  cin >> m;
  for(int i=0; i<m; i++) {
    int tx, ty; cin >> tx >> ty;
    
    if(x.end() == find(x.begin(), x.end(), tx)) x.push_back(tx);
    if(y.end() == find(y.begin(), y.end(), ty)) y.push_back(ty);
  }

  sort(starx.begin(), starx.end());
  sort(x.begin(), x.end());
  sort(stary.begin(), stary.end());
  sort(y.begin(), y.end());

  checker = {0, 0};
  int i=-starx[0];
  while(checker.first == 0 && i <= int(x.size() - starx.size())) {
    if(check(i, starx, x)) {
      checker.first = i;
      break;
    }

    i++;
  }

  i=-stary[0];
  while(checker.second == 0 && i <= int(y.size() - stary.size())) {
    if(check(i, stary, y)) {
      checker.second = i;
      break;
    }

    i++;
  }

  cout << checker.first << " " << checker.second;


  return 0;
}
