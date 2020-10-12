#include <iostream>
#include <cstring>

using namespace std;

const int LENGTH = 101;
int board[LENGTH][LENGTH];
int N;

int main(){
  memset(board, 0, sizeof board);

  cin >> N;

  int x, y;

  while(N--){
    cin >> x >> y;
    for(auto i=x; i<x+10; i++){
      for(auto j=y; j<y+10; j++){
        board[i][j] = 1;
      }
    }
  }

  int answer=0;

  for(auto i=1; i<LENGTH; i++){
    for(auto j=1; j<LENGTH; j++){
      if(board[i][j]) answer++;
    }
  }

  cout << answer;

  return 0;

}
