#include <iostream>

#define FOR(i, en) for (int i = 0; i < en; i++)

long long dp[21][100];
int N;
int n[100];

long long recur(int idx, int carryout)
{
    if (dp[carryout][idx] != -1)
        return dp[carryout][idx];

    if (idx == N - 2)
        if (n[idx] == 0) // 이 케이스를 고려하지 못해서 1회 오답처리
            return (carryout == n[idx]) ? 2 : 0;
        else
            return (carryout - n[idx] == n[idx + 1] || carryout + n[idx] == n[idx + 1]) ? 1 : 0;

    dp[carryout][idx] = 0;
    if (carryout - n[idx] >= 0)
        dp[carryout][idx] += recur(idx + 1, carryout - n[idx]);

    if (carryout + n[idx] <= 20)
        dp[carryout][idx] += recur(idx + 1, carryout + n[idx]);

    return dp[carryout][idx];
};

int main()
{
    // init
    FOR(i, 21)
    FOR(j, 100)
    dp[i][j] = -1;

    std::cin >> N;
    FOR(i, N)
    std::cin >> n[i];

    std::cout << recur(1, n[0]) << std::endl;

    return 0;
}