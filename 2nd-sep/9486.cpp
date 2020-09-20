#include <iostream>

int main(){
  string name;

  while(1){
    cin >> name;
    if(name == '0') break;

    vector<int> selector;
    for(auto i=0; i<name.size(); i++){
      selector.push_back(i);
    }

    do{
      char curchar = 'A';
      int cursor = 0;
      int count = 0;
      for(auto i=0; i<name.size(); i++){
        int index = distance(selector.begin(), find(selector.begin(), selector.end(), i));
        // move
        count += index-cursor;

        // changechar
        count += min(name[index] - 'A', 
      }

    }while(prev_permutation(selector.begin(), selector.end()))
  }
  return 0;
}
