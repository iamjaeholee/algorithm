#include <iostream>
#include <set>
#include <vector>

typedef std::vector<std::vector<int> > vii;

bool validator(const int node, const int &n)
{
    if (node > 0 && node <= n)
        return true;
    return false;
}

int dp(const int node, std::set<int> &footprint, const int &n, vii &memo)
{
    // mark node
    footprint.insert(node);

    // when complete traveling
    if (footprint.size() == n) {
        footprint.erase(node);
        return 1;
    }

    int result = 0;
    // moving
    for (int i = -1; i < 3; i++)
    {
        // escape standing
        if (i == 0)
            continue;

        // if validate moving
        if (validator(node + i, n) && footprint.count(node + i) == 0)
        {
            int m = memo[node][node + i];
            if (m != -1)
                result += m;
            else
            {
                int dpcount = dp(node + i, footprint, n, memo);
                memo[node][node + i] = dpcount;
                result += dpcount;
            }
        }
    }


    footprint.erase(node);
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::set<int> footprint;
    vii memo(n + 1, std::vector<int>(4, -1));
    std::cout << dp(1, footprint, n, memo) % 1000000009;
    return 0;
}