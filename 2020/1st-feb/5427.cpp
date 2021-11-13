#include <iostream>
#include <vector>
#include <climits>

std::pair<int, int> direction[4]{{1, 0},{-1, 0},{0, 1},{0,-1}};
int answer;

void dfs(std::pair<int, int> location, std::vector<std::vector<char>> map, std::pair<int, int> size, int count) {
  if(location.first == 0 || location.first == size.first-1 || location.second == 0 || location.second == size.second-1)  {
    answer = std::min(answer, count+1);
    return;
  } // check it is possible

  for(int i=0; i<size.first; i++) {
    for(int j=0; j<size.second; j++) {
      if(map[i][j] == '*') { //move fire
        for(int k=0; k<4; k++) {
          int nextI = i + direction[k].first;
          int nextJ = j + direction[k].second;
          if(nextI < 0 || nextI >= size.first || nextJ < 0 || nextJ >= size.second)  continue; // continue when stand on outside
          if(map[nextI][nextJ] == '.') map[nextI][nextJ] = '!'; //fire
        }
      }
    }
  }
  for(int i=0; i<size.first; i++) {
    for(int j=0; j<size.second; j++) {
      if(map[i][j] == '!') { //change to fire
        map[i][j] = '*';
      }
    }
  }

  for(int i=0; i<4; i++) {
    int nextI = location.first + direction[i].first;
    int nextJ = location.second + direction[i].second;
    if(map[nextI][nextJ] == '.') dfs(std::make_pair(nextI, nextJ), map, size, count+1); // move
  }

  return;
}

int main (){
  int T;
  std::cin >> T;
  while(T--) {
    int w, h;
    std::cin >> w >> h;
    std::vector<std::vector<char>> map;
    std::pair<int, int> location;

    for(int i=0; i<h; i++) {
      std::vector<char> width;
      for(int j=0; j<w; j++) {
        char temp;
        std::cin >> temp;
        if(temp == '@') { // find current location
          location = std::make_pair(i, j);
          temp = '.';
        }
        width.push_back(temp);
      }
      map.push_back(width);
    }

    // dfs
    answer=INT_MAX; //init
    dfs(location, map, std::make_pair(h, w), 0);
    if(answer == INT_MAX) std::cout << "IMPOSSIBLE" << std::endl;
    else std::cout << answer << std::endl;
  }

  return 0;
}