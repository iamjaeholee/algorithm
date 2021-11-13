#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Dice {
  public:
    int n;
    vector<int> board[5];
    int numbers[10];
    int score;

    Dice() {
      //initialize
      board[0] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38};
      board[1] = {10, 13, 16, 19};
      board[2] = {20, 22, 24};
      board[3] = {30, 28, 27, 26};
      board[4] = {25, 30, 35, 40, -1};
      score = 0;
      n = 10;

      for(auto i=0; i<n; i++) {
        scanf("%d", &numbers[i]);
      }
    }

    void findMaximumScore(int index, int tempScore, int firstPlayerKey, int firstPlayerValue, int secondPlayerKey, int secondPlayerValue, int thirdPlayerKey, int thirdPlayerValue, int forthPlayerKey, int forthPlayerValue) {
      if(index < n) {
        int keys[4];
        int values[4];

        for(auto i=0; i<4; i++) {
          keys[0] = firstPlayerKey;
          keys[1] = secondPlayerKey;
          keys[2] = thirdPlayerKey;
          keys[3] = forthPlayerKey;
          values[0] = firstPlayerValue;
          values[1] = secondPlayerValue;
          values[2] = thirdPlayerValue;
          values[3] = forthPlayerValue;

          // whether key lies in des
          if(board[keys[i]][values[i]] == -1) continue;

          int tempKey = keys[i];
          int tempValue = values[i] + numbers[index];

          // checking key
          if( (board[tempKey].size() - 1) < tempValue) {
            int newValue = tempValue - board[tempKey].size();

            switch(tempKey) {
              case 0:
                tempKey = 4;
                
                if(newValue >= 1) {
                  tempValue = 4;
                } else {
                  tempValue = newValue;
                }
                break;
              case 1:
              case 2:
              case 3:
                tempKey = 4;
                
                if(newValue >= 4) {
                  tempValue = 4;
                } else {
                  tempValue = newValue;
                }
                break;
              case 4:
                tempValue = 4;
                break;
            }
          }

          if(tempKey == 0 && tempValue == 5) {
            tempKey = 1;
            tempValue = 0;
          }
          if(tempKey == 0 && tempValue == 10) {
            tempKey = 2;
            tempValue = 0;
          }
          if(tempKey == 0 && tempValue == 15) {
            tempKey = 3;
            tempValue = 0;
          }

          // moving keys
          if(board[tempKey][tempValue] == -1) {
            keys[i] = tempKey;
            values[i] = tempValue;
            findMaximumScore(index + 1, tempScore, keys[0], values[0], keys[1], values[1], keys[2], values[2], keys[3], values[3]); 
          } else {
            if (i != 0) if (tempKey == keys[0] && tempValue == values[0]) continue;
            if (i != 1) if (tempKey == keys[1] && tempValue == values[1]) continue;
            if (i != 2) if (tempKey == keys[2] && tempValue == values[2]) continue;
            if (i != 3) if (tempKey == keys[3] && tempValue == values[3]) continue;

            keys[i] = tempKey;
            values[i] = tempValue;
            findMaximumScore(index + 1, tempScore + board[tempKey][tempValue], keys[0], values[0], keys[1], values[1], keys[2], values[2], keys[3], values[3]); 
          }
        }
      }

      if(index == n) {
        if(tempScore > score) {
          score = tempScore;
        }
      }
    }
};

int main() {
  Dice dice;

  dice.findMaximumScore(0, 0, 0,0, 0,0, 0,0, 0,0);

  printf("%d", dice.score);

  return 0;

}
