#include <iostream>
#include <vector>

void calcAnswer(std::vector<int>& v, int& firstH, int& secondH, int& answer){
  int lower = std::min(v[firstH], v[secondH]);
  for(int j = firstH+1; j<secondH; j++) answer += lower - v[j];
  firstH = secondH;
  secondH = -1;
}

int main(){
  int H, W;
  std::cin >> H >> W;

  std::vector<int> v(W);
  int firstH=0, secondH=-1, prevI=0, answer=0;

  for(int i=0; i<W; i++){
    std::cin >> v[i];
    int cur = v[i];
    int prev = v[prevI];

    if(i == 0) continue; // pass first arg

    if(cur > prev) secondH = i; // 올라가는 구간에서는 계속 저장
    else if(secondH != -1) calcAnswer(v, firstH, secondH, answer); // 내려가는 구간 시작점에서 빗물계산
    if(secondH != -1 && i == W-1) calcAnswer(v, firstH, secondH, answer); // 끝점을 만났을 대 빗물계산

    prevI = i;
  }

  std::cout << answer;

  return 0;
}