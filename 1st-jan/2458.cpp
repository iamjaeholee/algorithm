#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX_STUDENT = 501;
vector<int> smaller[MAX_STUDENT];
vector<int> taller[MAX_STUDENT];
int checker[MAX_STUDENT];
int N, M, answer=0, visited;

void tallerDFS(int node) {
  if(!checker[node]) {
    checker[node] = 1;
    visited++;
  }

  for(auto nextNode: taller[node]) if(!checker[nextNode]) tallerDFS(nextNode);
}
void smallerDFS(int node) {
  if(!checker[node]) {
    checker[node] = 1;
    visited++;
  }

  for(auto nextNode: smaller[node]) if(!checker[nextNode]) smallerDFS(nextNode);
}

int main(){
  cin >> N >> M;
  for(auto i=0; i<M; i++) {
    int s, g; cin >> s >> g;
    smaller[g].push_back(s);
    taller[s].push_back(g);
  }


  for(auto i=1; i<=N; i++) {
    memset(checker, 0, sizeof checker);
    visited=0;
    smallerDFS(i);
    tallerDFS(i);

    if(visited == N) answer++;
  }

  cout << answer;

  return 0;
}