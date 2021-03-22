#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

int main(){
  int ans=0;
  char map[5][5];
  for(int i=0; i<5; i++) {
    std::cin >> map[i];
  }

  std::vector<int> v, checker;
  std::queue<int> q;
  std::pair<int, int> directions[4]{{1, 0}, {-1,0}, {0,1}, {0,-1}};

  v.assign(18, 0);
  for(int i=0; i<7; i++){
    v.push_back(1);
  }

  
  do{
    int s=0;
    int y=0;
    std::vector<int> member;
    for(int i=0; i<25; i++){
      if(v[i] == 0) continue;

      member.push_back(i);
      int row = i/5;
      int column = i%5;

      if(map[row][column] == 'S') s++;
      else if(map[row][column]=='Y') y++;
    }

    if(s < y) continue; // continue when S is more less than Y
    checker.assign(v.begin(), v.end()); // copy v to checker
    int count=0;
    q.push(member[0]);
    checker[member[0]]=0;
    count++;

    while(!q.empty()){
      int start=q.front();
      q.pop();

      int row = start/5;
      int column = start%5;
      for(int i=0; i<4; i++){
        int nextR = row+directions[i].first;
        int nextC = column+directions[i].second;
        for(int i=0; i<7; i++){
          if(member[i]/5 == nextR && member[i]%5 == nextC && checker[member[i]] == 1){
            q.push(member[i]);
            checker[member[i]]=0;
            count++;
          }
        }
      }
    }

    if(count == 7) ans++;
  } while(std::next_permutation(v.begin(), v.end()));

  std::cout << ans;

  return 0;
}