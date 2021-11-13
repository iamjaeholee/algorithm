// 22 5
// 1 2 3 4 5

#include <iostream>
#include <vector>
#include <climits>

int main(){
  int N, M;
  std::cin >> N >> M;
  std::vector<long long> v;

  for(int i=0; i<M; i++){
    long long temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  long long left=0, right=600000000000, mid, result, t=0;

  while(left <= right){

    mid=(right+left)/2;
    result=M;
    for(int i=0; i<M; i++) result+=mid/v[i];

    if(result < N) left = mid+1;
    else {
      t=mid;
      right = mid-1;
    }
  }

  long long prev=M;
  for(int i=0; i<M; i++) prev+=(t-1)/v[i]; // prev value

  for(int i=0; i<M; i++) {
    if(t%v[i] == 0) prev++;
    if(prev == N){
      std::cout << i+1;
      break;
    }
  }

  return 0;
}