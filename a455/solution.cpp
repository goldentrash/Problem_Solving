#include <iostream>

int N;
int arr[100'001];
long long cache[100'001];

long long dp(int n);

int main()
{
    int max = 0;

    std::cin >> N;
    for (int n = 0; n < N; n++)
    {
        int tmp;
        std::cin >> tmp;
        arr[tmp]++;

        max = (max > tmp) ? max : tmp;
    }

    for (int n = 0; n <= max; n++)
        cache[n] = -1;

    std::cout << dp(max) << std::endl;

    return 0;
}

long long dp(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return arr[n];

    long long &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = std::max((long long)arr[n] * n + dp(n - 2),
                          (long long)arr[n - 1] * (n - 1) + dp(n - 3));
}