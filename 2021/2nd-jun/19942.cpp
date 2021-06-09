#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int mp, mf, ms, mv;

struct Ingredient{
  int num;
  int p;
  int f;
  int s;
  int v;
  int c;
} ingredient;

bool compare(const Ingredient& a, const Ingredient& b) {
  return a.c < b.c ? true : false;
}

void selectIngredients(const std::vector<Ingredient>& ingredients, const int& amount, const int& N, int& cost, std::vector<int>& answer){
  std::vector<int> selector(N);

  for(int i=0; i<amount; i++){
    selector[i] = 1;
  }

  do{
    int p=0, f=0, s=0, v=0, c=0;
    for(int i=0; i<N; i++){
      if(selector[i] == 1) {
        p+=ingredients[i].p;
        f+=ingredients[i].f;
        s+=ingredients[i].s;
        v+=ingredients[i].v;
        c+=ingredients[i].c;
      }
    }

    if(p >= mp && f >= mf && s >= ms && v >= mv && c < cost) { // 만약 선택한 재료들이 조건을 충족한다면
      cost=c;
      answer = selector;
    }

  }while(std::prev_permutation(selector.begin(), selector.end()));
}

int main(){
  int N;
  std::cin >> N;

  std::cin >> mp >> mf >> ms >> mv;

  std::vector<Ingredient> ingredients;
  for(int i=0; i<N; i++){
    std::cin >> ingredient.p >> ingredient.f >> ingredient.s >> ingredient.v >> ingredient.c;
    ingredient.num = i+1;
    ingredients.push_back(ingredient);
  }

  std::sort(ingredients.begin(), ingredients.end(), compare); // 값을 기준으로 정렬
  std::vector<int> answer;
  int cost=INT_MAX;

  for(int i=1; i<=N; i++){
    selectIngredients(ingredients, i, N, cost, answer);
  }

  if(cost==INT_MAX) std::cout << -1;
  else {
    std::cout << cost << std::endl;
    std::vector<int> temp;
    for(int i=0; i<N; i++){
      if(answer[i] == 1) temp.push_back(ingredients[i].num);
    }
    std::sort(temp.begin(), temp.end());
    for(auto a: temp) std::cout << a << " ";
  }

  return 0;
}