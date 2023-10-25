#include <iostream>

const int MOD = 1'000'000'007;

int C, N;
int ret;

int cache[50];

void clearCache();
int dp(int len);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N;

        bool isEven = N >> 1 << 1 == N;

        N >>= 1;
        clearCache();
        int v1 = dp(0);

        N -= 1;
        clearCache();
        int v2 = dp(0);

        if (isEven)
        {
            ret = (long long)v1 * (v1 - 1) % MOD;
            ret += (long long)v2 * (v2 - 1) % MOD;
            ret %= MOD;
        }
        else
        {
            ret = (long long)v1 * (v1 - 1) % MOD;
            ret += (long long)v1 * v2 * 2 % MOD;
            ret %= MOD;
        }

        std::cout << ret << std::endl;
    }

    return 0;
}

int dp(int len)
{
    if (len == N)
        return 1;
    if (len > N)
        return 0;

    int &ret = cache[len];
    if (ret != -1)
        return ret;

    ret = (dp(len + 1) + dp(len + 2)) % MOD;
    return ret;
}

void clearCache()
{
    for (int i = 0; i < 50; i++)
        cache[i] = -1;
}