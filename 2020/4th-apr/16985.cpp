#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> const & temp){
  std::vector<std::vector<int>> newTemp;

  for(int i=0; i<5; i++){
    std::vector<int> newRow;

    for(int j=4; j>=0; j--){
      newRow.push_back(temp[j][i]);
    }

    newTemp.push_back(newRow);
  }

  return newTemp;
}

int main(){

  std::vector<std::vector<std::vector<int>>> map;
  for(int i=0; i<5; i++){
    std::vector<std::vector<int>> v;
    for(int j=0; j<5; j++){
      std::vector<int> temp(5);
      for(int k=0; k<5; k++){
        std::cin >> temp[k];
      }
      v.push_back(temp);
    }

    map.push_back(v);
    v = rotate(v);
    map.push_back(v);
    v = rotate(v);
    map.push_back(v);
    v = rotate(v);
    map.push_back(v);
  } // make map


  // make permutation
  std::vector<int> selector;

  for(int i=0; i<20; i++) {
    if(i < 5) selector.push_back(5-i);
    else selector.push_back(0);
  }

  int answer=-1;
  std::vector<std::vector<int>> tempRow;
  std::vector<std::vector<std::vector<int>>> tempMap(5, tempRow);

  do {
    int checker[5]{0};

    for(int i=0; i<20; i++){
      int number = selector[i];
      if(number == 0) continue;
      else {
        tempMap[number-1] = map[i];
        checker[i/4] = 1;
      }
    }

    // if(checker[0] && checker[1] && checker[2] && checker[3] && checker[4] && newMap[0][0][0] == 1 && newMap[4][4][4] == 1) {
    //   std::cout<< 'test';
    //   // answer = std::min(bfs(newMap), answer);
    // }

  } while(std::prev_permutation(selector.begin(), selector.end()));

  return 0;
}