#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 


  map<string, int> m;
  map<string, int>::iterator it;
  string s;
  int a = 0;

  while(getline(cin, s)){
    it = m.find(s);
    if(it != m.end()) it->second = it->second+1;
    else m.insert(pair<string, int>(s, 1));
    a++;
  }

  //print
  for(it=m.begin(); it!=m.end(); ++it){
    cout << it->first << " " << fixed<<setprecision(4) << (double)it->second / (double)a * 100 << endl;
  }
  
}
