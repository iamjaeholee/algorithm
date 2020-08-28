#include <stdio.h>

int main () {
  int height, n;
  // input values from stdin
  scanf("%d%d", &height, &n);

  int cylinders[height];

  // check the input
  if(height < n) {
    printf("%d", 0);
    return 0;
  }
  
  for (auto i = 0; i < height; i++) {
    scanf("%d", &cylinders[i]);
  }

  // core
  for (auto i = 0; i < n; i++) {
    int diskWeight;
    scanf("%d", &diskWeight);

    for (auto j = 0; j < height; j++) {
      if (diskWeight > cylinders[j]) {
        height = j;

        if (height == 0 && i != n-1) {
          printf("%d", height);
          return 0;
        }

        break;
      }
    }
  }

  printf("%d", height);
}
