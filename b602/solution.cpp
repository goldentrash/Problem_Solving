#include <iostream>

int main()
{
    int N;
    int arr[100'000];

    std::cin >> N;
    for (int n = 0; n < N; n++)
        std::cin >> arr[n];

    int st = 0;
    while (st + 1 < N && arr[st] == arr[st + 1])
        st++;

    if (st + 1 == N)
    {
        std::cout << N << std::endl;
        return 0;
    }

    int ret = st + 1;
    int pre = 0;
    int tmp = st + 1;
    int dir = arr[st + 1] - arr[st];
    for (int n = st + 2; n < N; n++)
    {
        if (arr[n] == arr[n - 1])
            continue;

        if (dir * (arr[n] - arr[n - 1]) > 0)
        {
            ret = std::max(ret, n - pre);
            pre = tmp;
        }
        else
        {
            dir *= -1;
        }

        tmp = n;
    }
    ret = std::max(ret, N - pre);

    std::cout << ret << std::endl;

    return 0;
}