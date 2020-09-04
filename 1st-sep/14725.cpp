#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct den{
  string food;
  vector<den*> next;

  den(string s = ""):food(s) {}
};

bool compareByName(const den* a, const den* b)
{
    return a->food <= b->food;
}

void print(int level, den* d) {
  sort(d->next.begin(), d->next.end(), compareByName);

  for(auto i=0; i<level; i++){
    cout << '-';
  }
  cout << d->food << "\n";

  for(auto x: d->next){
    print(level + 2, x);
  }
}

int main() {
  int n, k;
  cin >> n;
  den* root = new den;

  while(n--) {
    cin >> k;
    cin.ignore();

    string s;
    den* current = root;

    while(k--) {
      bool checker = 0;
      cin >> s;
      
      // case 1. has nexts
      for(auto i=0; i<current->next.size(); i++){
        // when found same string
        if(!current->next[i]->food.compare(s)){
          current = current->next[i];
          checker = 1;
          break;
        }
      }

      if(checker) continue;

      // case 2. no have nexts or no found same string
      den* tmp = new den(s);
      current->next.push_back(tmp);
      current = current->next[current->next.size()-1];
    }
  }

  sort(root->next.begin(), root->next.end(), compareByName);

  for(auto x: root->next){
    print(0, x);
  }
  return 0;
}
