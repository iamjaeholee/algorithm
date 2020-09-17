#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX=50;

char m[MAX][MAX];
int ch[MAX][MAX];
int height[MAX][MAX];
int hlist[MAX*MAX];
int N,S;

void dfs(int x, int y, int mi, int mx){
  if(ch[x][y]) return;
  ch[x][y] = 1;

  for(auto i=-1; i<=1; ++i)
    for(auto j=-1; j<=1; ++j)
      if(i || j){
        int nx = x + i;
        int ny = y + j;
        
        if(height[nx][ny] < mi || height[nx][ny] > mx || nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
        dfs(nx, ny, mi, mx);
      }
}

bool check(int mi, int mx){
  memset(ch, 0, sizeof ch);

  for(auto i=0; i<N; i++)
    for(auto j=0; j<N; j++)
      if(m[i][j] == 'P'){
        if(height[i][j] < mi || height[i][j] > mx) return false;
        dfs(i, j, mi, mx);
      }

  for(auto i=0; i<N; i++)
    for(auto j=0; j<N; j++)
      if(m[i][j] == 'K' && !ch[i][j])
        return false;

  return true;
}

int main(){
  S = 0;

  cin >> N;
  for(auto i=0; i<N; i++){
    cin >> m[i];
  }

  for(auto i=0; i<N; i++){
    for(auto j=0; j<N; j++){
      cin >> height[i][j];
      hlist[S++] = height[i][j];
    }
  }

  sort(hlist, hlist+S);
  S = unique(hlist, hlist+S) - hlist;

  int result = 1 << 30;
  
  for(int i=0; i<S; ++i){
    int lo = i;
    int hi = S-1;
    while(lo<hi){
      int tem = lo + (hi-lo)/2;
      if(check(hlist[i], hlist[tem])){
        hi = tem;
      } else {
        lo = tem+1;
      }
    }
    
    if(check(hlist[i], hlist[lo])){
      result = min(result, hlist[lo] - hlist[i]);
    }
  }

  cout << result;

  return 0;
}
