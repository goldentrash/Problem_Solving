#include <iostream>

int N;
int height[5'000];

int calc(int st, int en);

int main()
{
    std::cin >> N;

    for (int n = 0; n < N; n++)
        std::cin >> height[n];

    std::cout << calc(0, N) << std::endl;

    return 0;
}

int calc(int st, int en)
{
    if (en == st)
        return 0;

    int min = 1'000'000'000;
    for (int f = st; f < en; f++)
    {
        if (min > height[f])
            min = height[f];
    }

    if (min >= en - st)
        return en - st;

    int ret = min;
    int nxtSt = st;
    for (int f = st; f < en; f++)
    {
        height[f] -= min;

        if (!height[f])
        {
            ret += calc(nxtSt, f);
            nxtSt = f + 1;
        }
    }
    ret += calc(nxtSt, en);

    return (ret < en - st) ? ret : en - st;
}