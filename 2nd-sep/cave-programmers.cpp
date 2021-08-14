#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int MAX{200000};

int n{9};
vector<int> tree[MAX];
vector<int> uni_tree[MAX];
vector<int> visit;
vector<int> finish;
int answer=1;

void dfs(int node){
  visit[node] = 1;

  for(auto next: uni_tree[node]){
    if(!visit[next]) dfs(next);
    else if(!finish[next]) {
      answer=0;
      return;
    }
  }

  finish[node] = 1;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(auto elements: path){
      int x = elements[0]; int y = elements[1];
      tree[x].push_back(y);
      tree[y].push_back(x);
    }

    queue<int> q;
    q.push(0);
    visit.assign(n, 0);

    while(!q.empty()){
      int node = q.front();
      visit[node] = 1;
      q.pop();

      for(auto next: tree[node]){
        if(!visit[next]){
          uni_tree[node].push_back(next);
          q.push(next);
        }
      }
    }

    visit.assign(n, 0);
    finish.assign(n, 0);

    for(auto elements: order){
      if(elements[1] == 0) return 0;
      int x = elements[0]; int y = elements[1];
      uni_tree[x].push_back(y);
    }

    dfs(0);
    
    return answer;
}
