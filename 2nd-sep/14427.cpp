#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  int a[n];
  for(auto i=0; i<n; i++) {
    cin >> a[i];
  }
  cin >> m;

  while(m--){
    int t, i, v;
    cin >> t;
    if(t==2) cout << distance(a, find(a, a+n, *min_element(a, a+n))) + 1 << "\n";
    else {
      cin >> i >> v;
      a[i-1] = v;
    }
  }
  return 0;
}