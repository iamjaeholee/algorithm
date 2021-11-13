#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;

  while(T--) {
    int N, M, K, answer=0;
    long long sum=0;
    std::vector<int> v;
    std::vector<long long> result;
    std::cin >> N >> M >> K;

    for(int i=0; i<N; i++) { //input
      int temp; std::cin >> temp;
      v.push_back(temp); sum+=temp;
      result.push_back(sum);
    }

    for(int i=0; i<M-1; i++) { //for clockwise
      sum += v[i];
      result.push_back(sum);
    }

    for(int i=0; i<N; i++) {
      long long calc;
      if(i == 0) calc = result[i+M-1];
      else calc = result[i+M-1] - result[i-1];
      if(calc < K) answer++;
    }

    std::cout << answer << std::endl;
  }

}