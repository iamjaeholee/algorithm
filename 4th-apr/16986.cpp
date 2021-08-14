#include <iostream>
#include <vector>
#include <algorithm>

void writeScore(
    std::vector<std::pair<int, int>> & score,
    std::pair<int, int> & match,
    int winner
){
  if(winner){
    score[match.first].first++;
    match.second = (match.second+1) % 3; while(match.first == match.second) match.second = (match.second+1) % 3;
  } else {
    score[match.second].first++;
    match.first = (match.first+1) % 3; while(match.first == match.second) match.first = (match.first+1) % 3;
  }
}

int main(){
  int N, K; std::cin >> N >> K;

  std::vector<std::vector<int>> hands;

  for(int i=0; i<N; i++){
    std::vector<int> temp(N);
    for(int j=0; j<N; j++){
      std::cin >> temp[j];
    }

    hands.push_back(temp);
  }

  std::vector<std::vector<int>> board;
  for(int i=0; i<3; i++){
    std::vector<int> temp;
    i==0 ? temp.assign(N, 0) : temp.assign(20, 0);
    for(int j=0; j<20; j++){
      if(i == 0){
        if(j == N) break;
        temp[j] = j+1;
      }
      else std::cin >> temp[j];
    }

    board.push_back(temp);
  }

  // play 
  int answer = 0;

  do {
    std::vector<std::pair<int, int>> score{{0, 0}, {0, 0}, {0, 0}};
    std::pair<int, int> match{0, 1};

    while(true){
      if(score[0].first == K) { // check possibility
        answer = 1;
        break;
      }
      else if(score[1].first == K || score[2].first == K || score[0].second == N || score[1].second == 20 || score[2].second == 20) break; // terminate

      // match
      int firstHand = board[match.first][score[match.first].second]-1;
      int secondHand = board[match.second][score[match.second].second]-1;
      score[match.first].second++;
      score[match.second].second++;
      int result = hands[firstHand][secondHand];

      result == 0 ? writeScore(score, match, 0) :
        result == 2 ? writeScore(score, match, 1) :
          match.first < match.second ? writeScore(score, match, 0) :
          writeScore(score, match, 1);
    }
  } while(std::next_permutation(board[0].begin(), board[0].end()));

  std::cout << answer;

  return 0;
}