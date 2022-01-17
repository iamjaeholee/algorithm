#include <iostream>
#include <climits>

int main(){
    int N, min=INT_MAX, max=INT_MIN;
    std::cin >> N;

    int prev=0;
    for(int i=0; i<N; i++){
        int temp;
        std::cin >> temp;
        int sum = prev + temp;
        min = std::min(min, sum);
        max = std::max(max, sum);

        prev=sum;
    }

    int result = (N == 1) ? min : max-min;
    std::cout << result;
    return 0;
}