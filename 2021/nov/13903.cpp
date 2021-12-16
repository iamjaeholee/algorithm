#include <iostream>
#include <vector>
#include <queue>

bool canMove(std::pair<int, int> &node, std::pair<int, int> &rule, std::vector<std::vector<int>> &checker, std::vector<std::vector<int>> &map, int &R, int &C)
{
    int nextR = node.first + rule.first;
    int nextC = node.second + rule.second;

    // wall check
    if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
        return false;
    if (map[nextR][nextC] == 0)
        return false;

    // not visited || already visited but this is more short way => visit
    if (checker[nextR][nextC] > checker[node.first][node.second] + 1 || checker[nextR][nextC] == 0)
        return true;

    return true;
}

int bfs(std::vector<std::vector<int>> &map, std::vector<std::pair<int, int>> &rules, std::vector<std::vector<int>> &checker, int &R, int &C, std::pair<int, int> start)
{
    std::queue<std::pair<int, int>> q;

    // land
    checker[start.first][start.second] = 1;
    q.push(start);

    while (!q.empty())
    {
        std::pair<int, int> node = q.front();
        q.pop();

        for (auto &rule : rules)
        {
            if (canMove(node, rule, checker, map, R, C))
            {
                int nextR = node.first + rule.first;
                int nextC = node.second + rule.second;

                // land
                checker[nextR][nextC] = checker[node.first][node.second] + 1;

                // check result
                if (nextR == R - 1)
                    return checker[nextR][nextC] - 1;

                q.push({nextR, nextC});
            }
        }
    }

    return -1;
}

int main()
{
    int R, C, N;
    std::cin >> R >> C;

    // get map
    std::vector<std::vector<int>> map;
    for (int i = 0; i < R; i++)
    {
        std::vector<int> temp(C, 0);
        for (int j = 0; j < C; j++)
        {
            std::cin >> temp[j];
        }

        map.push_back(temp);
    }

    // get rule
    std::cin >> N;
    std::vector<std::pair<int, int>> rules(N, {0, 0});
    for (int i = 0; i < N; i++)
    {
        std::cin >> rules[i].first;
        std::cin >> rules[i].second;
    }

    // make checker
    std::vector<std::vector<int>> checker;
    for (int i = 0; i < R; i++)
    {
        std::vector<int> temp(C, 0);
        checker.push_back(temp);
    }

    // BFS search
    int result = -1;
    for (int i = 0; i < C; i++)
    {
        if (map[0][i] == 1)
        {
            int bfsResult = bfs(map, rules, checker, R, C, {0, i});
            if (bfsResult)
            {
                result = result == -1 ? bfsResult : std::min(result, bfsResult);
            }
        }
    }

    std::cout << result;

    return 0;
}