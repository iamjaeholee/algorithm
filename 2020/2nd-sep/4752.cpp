#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int B, E;
string TEXT;

class Parse {
  public:
    vector<string> result;
    stack<string> tags;
    int toggle;
    int isEndtag;
    int isOnRange;
    string tems;
    string sub;

    void init(){
      toggle = 0; isEndtag = 0; tems = "";
    }

    void parsing(string origin){
      isOnRange = 1;
      init();

      for(auto i=0; i<origin.size(); i++){
        char temc = origin[i];

        if(i >= B && i <E) {
          sub += temc;
          continue;
        }

        if(toggle) { // tag is open
          if(temc == '/' && tems == "") {
            isEndtag = 1;
            continue;
          }

          if(temc == '>') { // proper tag
            if(isEndtag) {
              if(tags.empty()) continue;
              string tag = tags.top();
              tags.pop();

              if(tag == tems && isOnRange) {
                result.push_back(tems);
              }

              isOnRange = 1;
              init();
            } else {
              if(i >= E) isOnRange = 0;
              tags.push(tems);
              init();
            }

            init();
          }

          if( !((temc >= 48 && temc <= 57) || (temc >=65 && temc <=90) || (temc >= 97 && temc <=122) || temc == '-') ) { // invalid char inside tag
            init();
            continue;
          }
          
          tems += temc;
        }

        if(temc == '<') {
          toggle = 1;
        }
      }
    }

    void print(){
      for(auto x :result){
        sub = "<" + x + ">" + sub + "</" + x + ">";
      }

      cout << sub << "\n";
      clear();
    }

    void clear(){
      while(!tags.empty()) tags.pop();
      result.clear();
      sub = "";
    }

};

int main(){
  Parse p;

  while(1){
    cin >> B >> E;
    cin.ignore(1);
    if(B == -1 && E == -1) break;
    getline(cin, TEXT);
    p.parsing(TEXT);
    p.print();
  }


  return 0;
}
