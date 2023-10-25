// https://codeforces.com/problemset/problem/486/e

#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    int arr[N];
    int lis[N];
    int lds[N];
    int bs[N + 1];

    for (int n = 0; n < N; n++)
        std::cin >> arr[n];

    int maxLis = 0;
    for (int n = 0; n < N; n++)
    {
        int st = 1, en = maxLis + 1;
        while (st < en)
        {
            int mid = (st + en) / 2;
            if (bs[mid] < arr[n])
                st = mid + 1;
            else if (bs[mid] > arr[n])
                en = mid;
            else
                st = en = mid;
        }

        lis[n] = st;
        bs[st] = arr[n];

        if (lis[n] == maxLis + 1)
            maxLis = lis[n];
    }

    int maxLds = 0;
    for (int n = N - 1; n >= 0; n--)
    {
        int st = 1, en = maxLds + 1;
        while (st < en)
        {
            int mid = (st + en) / 2;
            if (bs[mid] > arr[n])
                st = mid + 1;
            else if (bs[mid] < arr[n])
                en = mid;
            else
                st = en = mid;
        }

        lds[n] = st;
        bs[st] = arr[n];

        if (lds[n] == maxLds + 1)
            maxLds = lds[n];
    }

    int optional[maxLis];
    for (int n = 0; n < N; n++)
        optional[n] = 0;
    for (int n = 0; n < N; n++)
    {
        if (lis[n] + lds[n] - 1 != maxLis)
            continue;

        optional[lis[n] - 1]++;
    }

    for (int n = 0; n < N; n++)
    {
        if (lis[n] + lds[n] - 1 != maxLis)
        {
            std::cout << 1;
            continue;
        }

        if (optional[lis[n] - 1] == 1)
            std::cout << 3;
        else
            std::cout << 2;
    }

    std::cout << std::endl;
    return 0;
}