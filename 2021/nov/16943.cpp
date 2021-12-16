#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int A, B;
    std::cin >> A >> B;
    std::string sta = std::to_string(A);
    std::string start = sta;

    while (std::prev_permutation(sta.begin(), sta.end()))
    {
        start = sta;
    }

    int result = -1;
    do
    {
        // stoi
        int temp = std::stoi(start);
        if (temp < B && start[0] != '0')
            result = std::max(result, temp);
    } while (std::next_permutation(start.begin(), start.end()));

    std::cout << result;

    return 0;
}