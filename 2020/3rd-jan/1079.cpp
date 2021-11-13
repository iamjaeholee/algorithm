#include <iostream>
#include <vector>
#include <algorithm>

int self;
int answer=0;
int value[16][16]{0};

void kill(std::vector<std::pair<int, int>> v, int night) {
  int participants = v.size();

  if(participants <= 1) {
    answer = std::max(answer, night);
  }

  if(participants % 2 == 0) { // night
    int vector_size=participants;
    for(int i=0; i<vector_size; i++) {
      std::vector<std::pair<int, int>> tv; tv.assign(v.begin(), v.end()); //copy
      if(tv[i].first != self) {// if not me
        for(int j=0; j<vector_size; j++) {
          tv[j] = {tv[j].first, tv[j].second+value[tv[i].first][tv[j].first]};
        }
        tv.erase(tv.begin() + i); // kill people
        kill(tv, night+1);
      }
    }
  } else { // morgan
    int vector_size=participants;
    std::vector<std::pair<int, int>> tv; tv.assign(v.begin(), v.end()); //copy
    std::sort(tv.begin(), tv.end(), [](std::pair<int, int>a, std::pair<int, int>b){
      if(a.second == b.second) return a.first < b.first;
      else return a.second > b.second;
    });
    if(tv[0].first == self) return;
    else {
      tv.erase(tv.begin());
      kill(tv, night);
    }
  }

  return;
}

int main() {
  std::vector<std::pair<int, int>> people;
  int cur=0;
  int N;
  std::cin >> N;

  for(int i=0; i<N; i++) {
    int temp;
    std::cin >> temp;
    people.push_back(std::make_pair(i, temp));
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      std::cin >> value[i][j];
    }
  }

  std::cin >> self; self-=1;

  kill(people, 0);

  std::cout << answer;
  return 0;
}