#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > vii;

int main(){
    int N;
    std::cin >> N;
    vii memo(N, std::vector<int>(3, 0));

    if(N == 1 || N == 2) {
        std::cout << 1;
        return 0;
    }

    // initial value
    memo[1][1] = 1;

    for(int i=2; i<N; i++) {
        memo[i][1] = memo[i-1][2];
        memo[i][2] = memo[i-1][2] + memo[i-1][1];
    }

    // answer
    std::cout << memo[N-1][1] + memo[N-1][2]*2;
    return 0;
}