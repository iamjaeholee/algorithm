#include <iostream>
#include <vector>
#include <climits>
#include <queue>


std::vector<std::pair<int, int>> g[1001];
int N, P, K;

bool isPossible(int cost){
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, 1});
    std::vector<int> dist(N+1, INT_MAX);
    dist[1] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int ks = -pq.top().first;
        pq.pop();
        if(dist[node] < ks) continue;
        for(int i=0; i<g[node].size(); i++){
            int next = g[node][i].first;
            int nextK = ks + (g[node][i].second > cost);
            if(dist[next] > nextK){
                dist[next] = nextK;
                pq.push({-nextK, next});
            }
        }
    }

    return dist[N] <= K;

}

int main(){
    std::cin >> N >> P >> K;

    for(int i=0; i<P; i++){
        int v1, v2, w; 
        std::cin >> v1 >> v2 >> w;
        g[v1].push_back({v2, w});
        g[v2].push_back({v1, w});
    }

    int answer=-1;
    int l=0, r=1e7;
    while( l <= r){
        int mid = (l + r) / 2;
        if(isPossible(mid)){
            answer=mid;
            r=mid-1;
        } else l=mid+1;
    }

    std::cout << answer;
    return 0;

}