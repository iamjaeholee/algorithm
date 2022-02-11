#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
    int N, M;
    std::cin >> N >> M;

    std::vector<int> woks(M);
    for(int i=0; i<M; i++) std::cin >> woks[i];

    std::set<int> sums;

    // initializing with one woks
    sums.insert(woks.begin(), woks.end());

    // insert two woks
    std::vector<int> selector(M, 0);

    // set selector number
    selector[0] = 1;
    selector[1] = 1;

    while(std::prev_permutation(selector.begin(), selector.end())) {
        int sum=0;
        for(int i=0; i<M; i++) if(selector[i] == 1) sum+=woks[i];
        sums.insert(sum);
    }
    
    return 0;
}