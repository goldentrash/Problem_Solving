#include <iostream>

const int MOD = 10'000'000;

int C, N;

int cache[100][100];

void clearCache();
int dp(int used, int befo);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N;

        clearCache();
        std::cout << dp(0, 0) << std::endl;
    }

    return 0;
}

void clearCache()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            cache[i][j] = -1;
}

int dp(int used, int befo)
{
    if (used == N)
        return 1;

    int &ret = cache[used][befo];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int c = 1; c + used <= N; c++)
    {
        ret += (long long)dp(used + c, c) * ((befo) ? c + befo - 1 : 1) % MOD;
        ret %= MOD;
    }

    return ret;
}