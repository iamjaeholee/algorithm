#include <iostream>
#include <map>

using namespace std;

int N;
map<int, int> m;
int max_rx;

int main() {
  cin >> N;
  int lx, rx, h; max_rx = 0;
  pair<int, int> prev{0, 0};

  while(N--) {
    cin >> lx >> h >> rx;
    for(auto i=lx; i<rx; i++){
      if(m[i] < h) m[i] = h;
    }

    if (rx > max_rx) max_rx = rx;

    if (N == 1) {
      for(auto i=prev.first + 1; i<=max_rx; i++){
        if(prev.second != m[i]) cout << i << " " << m[i] << " ";
        prev = {i, m[i]};
        m.erase(i);
      }
    }

    for(auto i=prev.first + 1; i<=lx; i++){
      if(prev.second != m[i]) cout << i << " " << m[i] << " ";
      prev = {i, m[i]};
      m.erase(i);
    }
  }


  cout << "\n";
  cout << sizeof(m);
  return 0;
}
