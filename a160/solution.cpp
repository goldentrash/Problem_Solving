#include <iostream>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    int sum = 0;
    int coin[N];
    for (int n = 0; n < N; n++)
    {
        std::cin >> coin[n];
        sum += coin[n];
    }

    std::sort(coin, coin + N, std::greater<int>());

    int ans = 0;
    int mySum = 0;
    for (int n = 0; n < N; n++)
    {
        mySum += coin[n];
        ans++;

        if (mySum << 1 > sum)
            break;
    }

    std::cout << ans << std::endl;

    return 0;
}