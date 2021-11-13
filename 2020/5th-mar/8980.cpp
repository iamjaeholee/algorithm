// 4 40
// 6
// 3 4 20
// 1 2 10
// 1 3 20
// 1 4 30
// 2 3 10
// 2 4 20

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main(){
    int N, C, M;
    std::cin >> N >> C >> M;

    std::vector<std::tuple<int, int, int>> v, q;

    for(int i=0; i<M; i++){
        int from, to, amount;
        std::cin >> from >> to >> amount;
        v.push_back({from, to, amount});
    }

    sort(v.begin(), v.end());


    int answer=0;
    int capa=C;

    for(int i=1; i<=N; i++){
        for(int j=0; j<q.size(); j++){
            int from, to, amount;
            std::tie(from, to, amount) = q[j];

            if(to == i){
                answer += amount;
                capa += amount;
            } 
        }

        for(int j=0; j<v.size(); j++){
            int from, to, amount;
            std::tie(from, to, amount) = v[j];

            if(from == i){
                if(capa >= amount){
                    q.push_back({from, to, amount});
                    capa-=amount;
                }
                else{
                    q.push_back({from, to, capa});
                    capa=0;
                }
            }
        }
    }

    std::cout << answer;

    return 0;
}