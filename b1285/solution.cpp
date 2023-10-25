#include <iostream>
#include <algorithm>

int T, N;
int tastiness[100'000];
long long pSum[100'001];

long long calc(int st, int en);

int main()
{
    std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        std::cin >> N;
        pSum[0] = 0;
        for (int n = 0; n < N; n++)
        {
            std::cin >> tastiness[n];
            pSum[n + 1] = tastiness[n] + pSum[n];
        }

        std::cout << ((pSum[N] > calc(0, N - 1) && pSum[N] > calc(1, N)) ? "YES" : "NO") << std::endl;
    }

    return 0;
}

long long calc(int st, int en)
{
    if (en - st == 1)
        return tastiness[st];

    int half = (st + en) / 2;

    long long lside = tastiness[half - 1];
    for (int i = half - 2; i >= st; i--)
        lside = std::max(lside, pSum[half] - pSum[i]);

    long long rside = tastiness[half];
    for (int i = half + 1; i < en; i++)
        rside = std::max(rside, pSum[i + 1] - pSum[half]);

    return std::max({lside + rside, calc(st, half), calc(half, en)});
}