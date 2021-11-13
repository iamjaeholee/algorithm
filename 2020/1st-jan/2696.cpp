#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int T, M;
  cin >> T;

  while(T--) {
    cin >> M; 
    cout << M / 2 + 1 << endl;

    vector<int> v;
    int count = 0;

    for(auto i=1; i<=M; i++) {
      int tmp; cin >> tmp; v.push_back(tmp);

      if(i % 2 == 1) {
        sort(v.begin(), v.end());
        cout << v[i/2] << " ";
        count++;
      }

      if(count == 10) {
        cout << endl;
        count = 0;
      }
    }

    cout << endl;
  }
  return 0;
}