#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

int N, M;
vector<tuple<int, int, int> > v;
set<int> answer, result, sub;

int main() {
  cin >> N >> M;
  for(int i=1; i<=M; i++){
    int a, b;
    cin >> a >> b;
    if(a > b) {
      v.push_back({a, -(b+N), i});
    } else {
      v.push_back({a+N, -(b+N), i});
      v.push_back({a, -(b), i});
    }
  }

  sort(v.begin(), v.end()); //sort the vector

  int lastEnd{0}; //set initial end
  for(tuple<int, int, int> m: v) {
    int s, e, i; tie(s, e, i) = m; e=-e;//destructuring
    if(e > lastEnd) {
      lastEnd = e;
      answer.insert(i);
    } else {
      sub.insert(i);
    }
  }

  set_difference(answer.begin(), answer.end(), sub.begin(), sub.end(),
    std::inserter(result, result.end()));

  for(auto a: result) cout << a << " ";

  return 0;
}