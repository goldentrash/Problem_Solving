#include <iostream>

int N;
int arr[500'000];
long long pSum[500'001];
int cnt[500'001];
int ans;

int main()
{
    std::cin >> N;
    pSum[0] = 0;
    for (int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        pSum[n + 1] = arr[n] + pSum[n];
    }

    long long trg = pSum[N] / 3;
    cnt[0] = 0;
    for (int n = 0; n < N; n++)
    {
        if (pSum[n + 1] == trg)
            cnt[n + 1] = cnt[n] + 1;
        else
            cnt[n + 1] = cnt[n];
    }

    ans = 0;
    for (int n = N - 1; n > 0; n--)
    {
        if (pSum[N] - pSum[n] == trg)
            ans += cnt[n - 1];
    }

    std::cout << ans << std::endl;

    return 0;
}