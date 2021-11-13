#include <iostream>
#include <climits>

int map[10][10];
int paper[4];
int answer=INT_MAX;

bool check(std::pair<int, int> position, int size){
  if(position.first+size < 10 && position.second+size < 10 && paper[size] != 0) {
    for(int i=0; i<=size; i++) {
      for(int j=0; j<=size; j++) {
        if(map[position.first+i][position.second+j] != 1) {
          return false;
        }
      }
    }

    return true;
  } else return false;
}

bool isDone() {
  for(int i=0; i<10; i++) {
    for(int j=0; j<10; j++) {
      if(map[i][j] == 1) return false;
    }
  }

  return true;
}

void change(std::pair<int, int> position, int value, int size) {
    if(value == 0) paper[size]--;
    else paper[size]++;

    for(int i=0; i<=size; i++) {
      for(int j=0; j<=size; j++) {
        map[position.first+i][position.second+j]=value;
      }
    }

    return;
}

void dfs(std::pair<int ,int> point, int count) {
  if(point.first > 9 || point.second > 9) { // terminate
    if(isDone()) answer=std::min(answer, count);
    return;
  }

  if(map[point.first][point.second] == 1) {
    for(int i=0; i<5; i++) {
      if(check(point, i))  {
        change(point, 0, i); // check

        if(point.second == 9) {
          dfs({point.first+1, 0}, count + 1);
        } else {
          dfs({point.first, point.second+1}, count + 1);
        }

        change(point, 1, i); //uncheck
      }
    }
  } else {
    if(point.second == 9) {
      dfs({point.first+1, 0}, count);
    } else {
      dfs({point.first, point.second+1}, count);
    }
  }

  return;
}

int main(){

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++) {
      std::cin >> map[i][j];
    }
  }

  for(int i=0; i<5; i++) {
    paper[i] = 5;
  }

  dfs({0, 0}, 0);

  if(answer==INT_MAX) {
    if(isDone()) std::cout<<0;
    else std::cout<<-1;
  } else {
    std::cout << answer;
  }

  return 0;
}