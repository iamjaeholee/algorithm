#include <iostream>

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

int main()
{
    int N, K, count = 0;
    std::cin >> N >> K;

    do
    {
        if (findCount(N) <= K)
        {
            std::cout << count;
            break;
        }

        N += 1;
        count += 1;
        if (N < 0)
        {
            std::cout << -1;
            break;
        }

    } while (true);

    return 0;
}
