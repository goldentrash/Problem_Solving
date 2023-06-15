// https://codeforces.com/problemset/problem/500/a

#include <iostream>

int main()
{
    int N, T;
    std::cin >> N >> T;
    int edge[N + 1];
    for (int n = 1; n < N; n++)
    {
        int w;
        std::cin >> w;
        edge[n] = w + n;
    }
    edge[N] = N + 1;

    int cur = 1;
    while (cur <= N)
    {
        if (cur == T)
        {
            std::cout << "YES" << std::endl;
            return 0;
        }

        cur = edge[cur];
    }
    std::cout << "NO" << std::endl;

    return 0;
}