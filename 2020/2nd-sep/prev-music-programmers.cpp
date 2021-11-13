#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
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


      int sI{0};

      for(auto i=0; i<playtime; i++){
        if(sI == m.size()){
          if(score[(i)%score.size()] == '#'){
            break;
          } else {
            if(time < playtime){
              answer = name;
              time = playtime;
            }
          }
        }

        int tempI = i%score.size();
        if(m[sI] == score[tempI]){
          sI++;
        }
      }
    }

    if(answer == "") answer = "`(None)`";
    return answer;
}
