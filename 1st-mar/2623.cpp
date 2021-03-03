#include <iostream>
#include <vector>
#include <queue>

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int>> v;
  std::vector<int> e;
  std::vector<int> ans;

  for (int i = 0; i < N; i++)
  {
    std::vector<int> temp;
    v.push_back(temp);
  } // init

  e.assign(N, 0); // init

  for (int i = 0; i < M; i++)
  {
    int m;
    std::cin >> m;

    int prev;
    int next;
    for (int j = 0; j < m; j++)
    {
      if (j == 0)
        std::cin >> prev;
      else if (j == 1) std::cin >> next;
      else
      {
        prev = next;
        std::cin >> next;
      }

      if (j > 0)
      {
        v[prev - 1].push_back(next - 1);
        e[next - 1] += 1;
      }
    }
  }

  std::queue<int> q;
  for (int i = 0; i < N; i++)
  {
    if (e[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    int node = q.front();
    ans.push_back(node);
    q.pop();

    for (int i = 0; i < v[node].size(); i++)
    {
      e[v[node][i]] -= 1;
      if (e[v[node][i]] == 0)
        q.push(v[node][i]);
    }
  }

  if (ans.size() == N){
    for(int i=0; i<ans.size(); i++) std::cout << ans[i]+1 << std::endl;
  } else {
    std::cout<<0;
  }

  return 0;
}