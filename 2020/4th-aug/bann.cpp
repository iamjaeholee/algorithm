#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
vector<string> banned_id = {"fr*d*", "abc1**"} ;

int main() {
  int answer = 0;
  vector<int> check;

  for(auto i=0; i<banned_id.size(); i++) {
    check.push_back(0);
  }
  for(auto i=banned_id.size(); i<user_id.size(); i++) {
    check.push_back(1);
  }

  do {
    int bannid_index = 0;

    for(auto i=0; i<user_id.size(); i++) {
      bool is_failed = false;
      if(check[i] == 1) continue;
      if(i!=0) bannid_index += 1;

      // break when no size match
      if(banned_id[bannid_index].size() != user_id[i].size()) break;

      for(auto j=0; j<banned_id[bannid_index].size(); j++) {
        if(banned_id[bannid_index][j] == '*') continue;
        if(banned_id[bannid_index][j] != user_id[i][j]) {
          is_failed = true;
          break;
        }
      }

      // break when no match
      if(is_failed) break;

      if(i == (user_id.size() - 1)) answer += 1;
    }

  } while(next_permutation(check.begin(), check.end()));

  return answer;
}
