#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m, s, d, u, v, p;
  vector<int> result;

  while(1) {
    scanf("%d%d%d%d", &n, &m, &s, &d);

    if ( n==0 && m==0 ) {
      break;
    }
    
    int a[n][n];
    bool check[n];
    memset(a, 0, sizeof(a));
    memset(check, false, sizeof(check));

    for(auto i=0; i<m; i++) {
      scanf("%d%d%d", &u, &v, &p);
      a[u][v] = p;
    }

    // bfs
    queue<int> q;
    check[s] = true;
    q.push(s);

    while(!q.empty()) {
      int node = q.front();
      q.pop();

      for (auto i=0; i<sizeof(a[node])/sizeof(int); i++) {
        int temp = a[node][i];

        // has the road ?
        if(temp > 0) {
          printf("%d %d %d\n", node, i, temp);
          // has the path ?
          if(i == d) {
            if(!count(result.begin(), result.end(), temp)) {
              result.push_back(temp);
            }
          } else if(!check[i]){
            // set value
            for(auto j=0; j<sizeof(a[i])/sizeof(int); j++) {
              if(a[i][j] > 0) a[i][j] += temp;
            }

            check[i] = true;
            q.push(i);
          }
        }
      }
    }

    if(result.size() >= 2) {
      sort(result.begin(), result.end()); 
      printf("%d\n", result[1]);
      result.clear();
    } else {
      printf("%d\n", -1);
    }
  }

  return 0;

}
