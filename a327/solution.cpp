// Prof. Kim's solution "Maximum subarray"
// 가장 작은 부분합을 반전시키면 된다.

// mine: Divide and Conquer & prefix sum
#include <iostream>
#include <algorithm>

int N;
bool arr[100];
int preSum[101];

int calc(int st, int en);

int main()
{
    std::cin >> N;
    for (int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        preSum[n + 1] = preSum[n] + arr[n];
    }

    if (preSum[N] == N)
        std::cout << N - 1 << std::endl;
    else
        std::cout << calc(1, N + 1) << std::endl;

    return 0;
}

int calc(int st, int en)
{
    if (st == en)
        return 0;
    if (st + 1 == en)
        return 1;

    int mid = (st + en) / 2;

    int l = 0, r = 0;
    for (int n = mid - 1; n >= st; n--)
    {
        int now = (preSum[n - 1] - preSum[st - 1]) + ((mid - n) - (preSum[mid - 1] - preSum[n - 1]));
        if (now > l)
            l = now;
    }
    for (int n = mid; n < en; n++)
    {
        int now = (preSum[en - 1] - preSum[n]) + ((n - (mid - 1)) - (preSum[n] - preSum[mid - 1]));
        if (now > r)
            r = now;
    }

    return std::max({calc(st, mid) + preSum[en - 1] - preSum[mid - 1],
                     calc(mid, en) + preSum[mid - 1] - preSum[st - 1],
                     l + r});
}