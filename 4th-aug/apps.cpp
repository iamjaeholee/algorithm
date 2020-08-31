#include <stdio.h>
#include <stdlib.h>

class Apps {
  public: 
  int n, m;
  int* mem;
  int* cost;
  int current;

  Apps() {
    scanf("%d%d", &n, &m);
    mem = (int*) malloc(n * sizeof(int));
    cost = (int*) malloc(n * sizeof(int));

    for(auto i=0; i < n; i++) {
      scanf("%d", &mem[i]);
    }
    for(auto i=0; i < n; i++) {
      scanf("%d", &cost[i]);
    }

    current = 65532;
  }

  void findLowerCost(int base, int baseCost, int index) {
    for(auto i = index; i < n; i++) {
      int tempMem = base + mem[i];
      int tempCost = baseCost + cost[i];

      if(tempMem == m) {
        if(tempCost < current) {
          current = tempCost;
        }
      }

      if(i < n-1) {
        findLowerCost(tempMem, tempCost, i+1);
      }
    }
  }
};

int main() {

  Apps app;

  app.findLowerCost(0, 0, 0);

  printf("%d", app.current);

  return 0;

}
