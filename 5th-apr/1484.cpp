#include <iostream>
#include <math.h>

int main(){
  int G;
  std::cin >> G;

  int x=2;
  int check=0;

  while(true){
    int xPow = x*x;

    if(xPow <= G) {
      x++;
      continue;
    } else if(xPow <= ((x-1)*(x-1) + G)) {
      int yPow = xPow-G;
      double srY = sqrt((double)yPow);

      if((srY - floor(srY)) == 0) {
        check=1;
        std::cout << x << std::endl;
      }

      x++;
    } else {
      break;
    }
  }

  if(!check) std::cout << -1;

  return 0;
}