// https://codeforces.com/problemset/problem/217/a

#include <iostream>
#include <algorithm>

struct v
{
    int x;
    int y;
    int id;
};

int main()
{
    int N;
    std::cin >> N;
    struct v arr[N];
    for (int n = 0; n < N; n++)
    {
        arr[n].id = n;
        std::cin >> arr[n].x >> arr[n].y;
    }

    int g[N];

    std::sort(arr, arr + N, [](struct v &a, struct v &b)
              { return a.x > b.x; });

    g[arr[0].id] = arr[0].id;
    for (int n = 1; n < N; n++)
    {
        if (arr[n].x == arr[n - 1].x)
            g[arr[n].id] = g[arr[n - 1].id];
        else
            g[arr[n].id] = arr[n].id;
    }

    std::sort(arr, arr + N, [](struct v &a, struct v &b)
              { return a.y > b.y; });

    for (int n = 1; n < N; n++)
    {
        if (arr[n].y == arr[n - 1].y)
        {
            int rn = g[arr[n].id];
            while (rn != g[rn])
                rn = g[rn];

            int rn1 = g[arr[n - 1].id];
            while (rn1 != g[rn1])
                rn1 = g[rn1];

            g[rn] = rn1;
        }
    }

    int cnt = 0;
    bool visit[N] = {false};
    for (int n = 0; n < N; n++)
    {
        int r = g[n];
        while (r != g[r])
            r = g[r];

        if (!visit[r])
        {
            visit[r] = true;
            cnt++;
        }
    }

    std::cout << cnt - 1 << std::endl;

    return 0;
}