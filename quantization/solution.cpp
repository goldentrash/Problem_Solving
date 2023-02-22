#include <iostream>
#include <algorithm>

int C, N, S;
int arr[100];
int sum[101], sqrSum[101];
int cache[10][101];

void clearCache();
int dp(int sect, int idx);
int calcVar(int st, int en);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N >> S;

        for (int n = 0; n < N; n++)
            std::cin >> arr[n];

        std::sort(arr, arr + N);

        sum[0] = sqrSum[0] = 0;
        for (int n = 1; n <= N; n++)
        {
            sum[n] = sum[n - 1] + arr[n];
            sqrSum[n] = sqrSum[n - 1] + arr[n] * arr[n];
        }

        clearCache();
        std::cout << dp(0, 1) << std::endl;
    }

    return 0;
}

void clearCache()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 101; j++)
            cache[i][j] = -1;
}

int dp(int sect, int idx)
{
    if (idx == N)
        return 0;
    if (sect == S)
        return 987654321;

    int &ret = cache[sect][idx];
    if (ret != -1)
        return ret;

    ret = 987654321;
    for (int size = 1; size + idx <= N; size++)
        ret = std::min(ret, calcVar(idx, size + idx) + dp(sect + 1, size + idx));

    return ret;
}

int calcVar(int st, int en)
{
    int ret = sqrSum[en - 1] - sqrSum[st - 1];
    ret -= (sum[en - 1] - sum[st - 1]) * (sum[en - 1] - sum[st - 1]) / (en - st);

    return ret;
}