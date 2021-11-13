#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int N, M, H, answer;

void dp(int cur, vector<int> v[N], int sum){
  if(cur >= N || sum > H) return;
  if(sum == H) {
    answer++;
  }

  dp(cur++, v, sum);

  for(auto i=0; i<v[cur].size(); i++){
    dp(cur++, v, sum+v[cur][i]);
  }
}

int main(){
  cin >> N >> M >> H;
  cin.ignore();

  string temp;
  string word;

  vector<int> v[N];

  for(auto i=0; i<N; i++){
    getline(cin, temp);
    istringstream input(temp);

    while(input >> word){
      v[i].push_back(stoi(word));
    }
  }


  answer=0;

  dp(0, v, 0);

  cout << answer;

  return 0;
}
