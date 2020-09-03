#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Piece{
  int x, y, d;
};

int n, k;
int board[13][13];
deque<int> dq[13][13];
vector<Piece> pieces;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

bool move() {
  for(auto i=0; i<k; i++){
    int x = pieces[i].x;
    int y = pieces[i].y;
    int d = pieces[i].d;

    if(dq[x][y].front() != i) continue;

    // move one block
    int nx = x + dx[d];
    int ny = y + dy[d];

    // case.1 no appropriate x and y or piece on number 2
    if(nx > n || nx == 0 || ny == 0 || ny > n || board[nx][ny] == 2) {
      //switch direction
      if(d == 1 || d==3) d++;
      else d--;

      nx = x + dx[d];
      ny = y + dy[d];

      //update direction
      pieces[i].d = d;

      if(nx > n || nx == 0 || ny == 0 || ny > n || board[nx][ny] == 2) {
        continue;
      } 
    }

    // case.2 red
    if(board[nx][ny] == 1) {
      while(!dq[x][y].empty()){
        int tmp = dq[x][y].back();
        dq[nx][ny].push_back(tmp);
        dq[x][y].pop_back();
        pieces[tmp].x = nx;
        pieces[tmp].y = ny;
      }
    }

    // case. 3 white
    if(board[nx][ny] == 0) {
      while(!dq[x][y].empty()){
        int tmp = dq[x][y].front();
        dq[nx][ny].push_back(tmp);
        dq[x][y].pop_front();
        pieces[tmp].x = nx;
        pieces[tmp].y = ny;
      }
    }
    
    if(dq[nx][ny].size() >= 4) return 1;
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> k;

  // chess board
  for(auto i=1; i<=n; i++){
    for(auto j=1; j<=n; j++){
      cin >> board[i][j];
    }
  }

  // pieces
  for(auto i=0; i<k; i++){
    int x, y, d;
    cin >> x >> y >> d;
    pieces.push_back({x, y, d});
    dq[x][y].push_back(i);
  }

  // games
  int turn=1;
  while(turn <= 1000){
    if(move()) {
      cout << turn;
      break;
    } else if(++turn > 1000) cout << -1;
  } 

  return 0;
}
