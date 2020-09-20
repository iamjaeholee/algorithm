#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

string m{"ABCDEFG"};
vector<string> musicinfos{"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};

int main() {
    string answer = "";

    int time = 0;
    for(auto music: musicinfos){
      stringstream ss(music);

      string stime, ftime, name, score;
      getline(ss, stime, ',');
      getline(ss, ftime, ',');

      int sm = stoi(stime.substr(0, 2)) * 60 + stoi(stime.substr(3, 5));
      int fm = stoi(ftime.substr(0, 2)) * 60 + stoi(ftime.substr(3, 5));
      int playtime = fm - sm;

      getline(ss, name, ',');
      getline(ss, score, ',');

      int ref = playtime / score.size();
      if(ref) {
        while(--ref){
          score += score;
        }
        score += score.substr(0, playtime % score.size());
      }

      cout << score << endl;

      if(int pos=score.find(m))
        if(pos+m.size()<score.size() && score[pos+m.size()] != '#')
          if(time < playtime) {
            answer = name;
            time = playtime;
          }
    }

    cout << answer;
    if(answer == "") answer = "`(None)`";
    return 0;
}
