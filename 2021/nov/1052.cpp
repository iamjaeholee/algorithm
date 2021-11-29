#include <iostream>
#include <math.h>
#include <vector>

int findCount(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

bool checkK(int count, int k)
{
    while (count <= k)
    {
        if (k == count)
            return true;
        k >>= 1;
    }

    return false;
}

int main()
{
    int N, K, count = 0;
    std::cin >> N >> K;

    do
    {
        if (checkK(findCount(N), K))
        {
            std::cout << count;
            break;
        }

        N += 1;
        count += 1;
        if (N == -1)
        {
            std::cout << N;
            break;
        }

    } while (true);

    return 0;
}
