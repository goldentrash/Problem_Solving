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
            sum[n] = sum[n - 1] + arr[n - 1];
            sqrSum[n] = sqrSum[n - 1] + arr[n - 1] * arr[n - 1];
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
    if (idx == N + 1)
        return 0;
    if (sect == S)
        return 987654321;

    int &ret = cache[sect][idx];
    if (ret != -1)
        return ret;

    ret = 987654321;
    for (int size = 1; size + idx <= N + 1; size++)
        ret = std::min(ret, calcVar(idx, size + idx) + dp(sect + 1, size + idx));

    return ret;
}

int calcVar(int st, int en)
{
    int a = (double)(sum[en - 1] - sum[st - 1]) / (en - st) + 0.5;
    int ret = sqrSum[en - 1] - sqrSum[st - 1];
    ret -= 2 * (sum[en - 1] - sum[st - 1]) * a;
    ret += a * a * (en - st);

    if (ret < 0)
        throw;

    return ret;
}