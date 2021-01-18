#include <iostream>
#include <algorithm>
#include <vector>

bool compairSecond (std::pair<int, int>& i,std::pair<int, int> j) { return (i.second<j.second); }

int main() {
  int N, M, T, K;
  std::cin >> N >> M >> T >> K;

  std::vector<std::pair<int,int>> v; // containers

  for(int i=0; i<T; i++) {
    int tw, th;
    std::cin >> tw >> th;
    v.push_back({tw, th});
  } 
  sort(v.begin(), v.end());
  
  int answer{0};
  std::pair<int, int> location{0, 0};
  for(int i=0; i<T; i++) {
    if(v[i].first + K > N) break; // check limit
    int tempIndex{0};
    for(int j=i; j<T; j++) { //iterate by width
      if(v[j].first <= v[i].first + K) tempIndex=j;
      else break;
    }

    std::vector<std::pair<int, int>> tv;
    tv.assign(v.begin() + i, v.begin() + tempIndex + 1);
    std::sort(tv.begin(), tv.end(), compairSecond);

    int tempHIndex{0};
    int tvSize = tv.size();
    for(int j=0; j<tvSize; j++) { //iterate by height
      if(tv[j].second + K > M) break; // check limit
      int tempAnswer{0};
      for(int k=j; k<tvSize; k++) {
        if(tv[k].second <= tv[j].second+K) {
          tempAnswer++;
          tempHIndex = k;
        }
        else break;
      }

      if(tempAnswer > answer) {
        answer = tempAnswer;
        location = {v[i].first, tv[j].second + K};
      }
    }
  }

  std::cout << location.first << " " << location.second << std::endl;
  std::cout << answer;

  return 0;
}