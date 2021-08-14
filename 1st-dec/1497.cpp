#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, M;
int answer = 1<<15;

void go(int prev, int sum, int cur){
  if((v[cur] ^ (1<<M)-1) == 0){
    answer = min(1, answer);
    return;
  }
  if(((prev | v[cur]) ^ (1<<M) -1) == 0) {
    answer = min(sum+1, answer);
    return;
  }

  for(auto i = cur+1; i<N; i++){
    go(prev | v[cur], sum+1, i);
  }
}

int main() {
  cin >> N >> M;

  for(auto i=0; i<N; i++){
    string temp;
    cin >> temp >> temp;
    
    int music = 0;
    for(auto j=M-1; j>=0; j--){
      if(temp[M-1-j] == 'Y'){
        int tempMusic = 1 << j;
        music = music | tempMusic;
      }
    }

    v.push_back(music);
  }

  go(0, 0, 0);

  cout << answer;

  return 0;
}

