#include <iostream>
#include <algorithm>

int N;
int dp[19];
int n[19];
char o[18];

int operate(int a, int b, char op);

int main()
{
    std::cin >> N;
    N = N / 2 + 1;
    for (int i = 0; i < N - 1; i++)
        std::cin >> n[i] >> o[i];
    std::cin >> n[N - 1];

    if (N == 1)
        return n[0];

    // base
    dp[0] = n[0];
    dp[1] = operate(dp[0], n[1], o[0]);

    // step
    for (int i = 2; i < N; i++)
    {
        dp[i] = std::max(operate(dp[i - 1], n[i], o[i - 1]), operate(dp[i - 2], operate(n[i - 1], n[i], o[i - 1]), o[i - 2]));
    }

    std::cout << dp[N - 1] << std::endl;

    return 0;
}

int operate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        throw;
    }
}