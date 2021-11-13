#include <iostream>

using namespace std;

int answer[10];
int sum;

void go(int temp, int number, bool toggle, int index){
  if(number == answer[index]) temp += 1;

  if(index == 9){
    if(temp >= 5) sum++;

    return;
  }

  for(auto i=1; i<6; i++){
    if(i == number) {
      if(!toggle) {
        go(temp, i, true, index+1);
      }
    } else {
      go(temp, i, false, index+1);
    }
  }

}

int main() {
  for(auto i=0; i<10; i++){
    cin >> answer[i];
  }

  for(auto i=1; i<6; i++){
    go(0, i, false, 0);
  }

  cout << sum;

  return 0;
}
