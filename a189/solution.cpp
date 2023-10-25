#include <iostream>
#include <algorithm>

int N, a, b, c;
int cache[4'001];

int dp(int n);

int main()
{
    std::cin >> N >> a >> b >> c;
    for (int n = 1; n <= N; n++)
        cache[n] = -1;

    std::cout << dp(N) << std::endl;

    return 0;
}

int dp(int n)
{

    if (n == 0)
        return 0;
    if (n < 0)
        return -987'654'321;

    int &ret = cache[n];
    if (ret != -1)
        return ret;

    ret = 1;
    return ret += std::max({dp(n - a), dp(n - b), dp(n - c)});
}