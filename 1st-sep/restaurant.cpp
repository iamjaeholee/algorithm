#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int n{200};
vector<int> weak{1, 5, 6, 10, 50, 60, 70, 100};
vector<int> dist{1, 2, 3, 4};

int main() {
  int fNumber = 1;
  int wSize = weak.size();
  int fSize = dist.size();

  sort(dist.begin(), dist.end(), greater<int>{});

  //loop until all friends come in
  while(fNumber <= fSize){

    do { // permutation
      int fIndex = 0; // friends index
      int wStart = 0; // start point
      int wIndex = 0; // weak index
      int counter = 0;
      int result = 0; // result

      // check whole start point
      while(wStart < wSize){
        int is_changed = wStart;
        fIndex = 0;
        wIndex = wStart;
        counter = 0;
        result = weak[wIndex] + dist[fIndex];

        while(counter < wSize){
          int curWeak=0;

          // change the vector position with value
          if(wIndex >= wSize){
            curWeak = weak[wIndex%wSize] + n;
          } else curWeak = weak[wIndex];

          // case 1. change friend
          if(curWeak > result){
            if(++fIndex < fNumber) {
              result = curWeak + dist[fIndex];
              continue;
            }
            // case 2. no friend reft change start point and loop again
            else {
              wStart++;
              break;
            }
          }

          ++counter; ++wIndex;
        }

        // if start point has not been changed return friends 
        if(is_changed == wStart){
          return fNumber;
        }

      }

    } while(prev_permutation(dist.begin(), dist.begin()+fNumber));

    //increase friends size
    fNumber++;
  }

  //failure
  return -1;
}
