#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int MAX{50000};
pair<int, int> input[MAX];
map<int, int> cameras;
int points;
int n;

int check(){
  sort(input, input+n);
  points = 0;
  cameras.clear();

  for(int i=0; i<n; i++){
    int y = input[i].second;
    if(cameras[y] == 0) points++;
    cameras[y] += 1;
  }

  if(points <= 3) return 1; // when 3 horisontal line success

  int i=0;
  while(i<n) {
    int j = i;
    while(j<n && input[i].first == input[j].first) j++;

    for(int k=i; k<j; k++){
      int y = input[k].second;
      cameras[y] -= 1;
      if(cameras[y] == 0) points--;
    }

    if(points <= 2) return 1; // when 2 horisontal line && 1 vertical line success

    for(int k=i; k<j; k++){
      int y = input[k].second;
      if(cameras[y] == 0) points++;
      cameras[y] += 1;
    }

    i = j;
  }

  return 0;
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> input[i].first;
    cin >> input[i].second;
  }

  if(check()){
    cout << 1;
  } else {
    for(int i=0; i<n; i++){
      swap(input[i].first, input[i].second);
    }
    if(check()){
      cout << 1;
    } else cout << 0; //fail
  }

  return 0;
}
