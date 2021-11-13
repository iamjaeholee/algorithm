#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 101;

string pattern, filename;
int plength, flength;
int memo[MAX][MAX];

bool checkPattern(int p, int f){
  if(p == plength && f == flength) return memo[p][f] = 1;
  if(memo[p][f] != -1) return memo[p][f];

  // if p index *
  if(pattern[p] == '*') {
    if(p < plength) if(checkPattern(p + 1, f)) return memo[p][f] = 1;  
    if(f < flength) if(checkPattern(p, f + 1)) return memo[p][f] = 1;
  }

  if(pattern[p] == filename[f]) {
    if(checkPattern(p + 1, f + 1)) return memo[p][f] = 1;
  }

  return memo[p][f] = 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  // get pattern
  getline(cin, pattern);
  plength = pattern.size();

  int n;
  cin >> n;
  cin.ignore();

  while(n--){
    memset(memo, -1, sizeof(memo));
    getline(cin, filename);
    flength = filename.size();

    if(checkPattern(0, 0)) cout << filename << "\n";
  }

  return 0;
}
