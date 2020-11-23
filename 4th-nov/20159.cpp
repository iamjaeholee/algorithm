#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int answer=0;
  int N;
  cin >> N;

  int cards[N];
  vector<int> odd;
  vector<int> even;


  for(auto i=0; i<N; i++){
    cin >> cards[i];
  }

  int oddSum=0;
  int evenSum=0;

  for(auto i=0; i<N-1; i++){
    if(i % 2 == 0) {
      oddSum += cards[i];
      odd.push_back(oddSum);
    } else {
      evenSum += cards[i];
      even.push_back(evenSum);
    }
  }

  int key = cards[N-1];
  int evenIndex = int(even.size()) - 1;

  for(auto i=0; i<(N/2); i++){
    int temp; 
    if(i == 0) temp = key + even[evenIndex]; 
    else temp = odd[i-1] + key  + even[evenIndex] - even[i-1];
    answer = max(temp, answer);
    if(i == 0) temp = odd[i] + even[evenIndex];
    else temp = odd[i] + even[evenIndex] - even[i-1];
    answer = max(temp, answer);
  }

  cout << answer;

  return 0;
}

