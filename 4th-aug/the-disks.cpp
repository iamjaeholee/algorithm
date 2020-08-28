#include <iostream>

using namespace std;

int main () {
  int height, n;
  // input values from stdin
  cin >> height >> n;

  int cylinders[height];

  // check the input
  if(height < n) {
    cout << 0;
    return 0;
  }
  
  for (auto i = 0; i < height; i++) {
    cin >> cylinders[i];
  }

  // core
  for (auto i = 0; i < n; i++) {
    int diskWeight;
    cin >> diskWeight;

    for (auto j = 0; j < height; j++) {
      if (diskWeight > cylinders[j]) {
        height = j;

        if (height == 0 && i != n-1) {
          cout << height;
          return 0;
        }

        break;
      }
    }
  }

  cout << height;
}
