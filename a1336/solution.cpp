#include <iostream>
#include <list>
#include <algorithm>

struct city
{
    int value;
    std::list<int> carr;
};

int N, K;
city narr[200'001];

int step(int now, int pre, int depth);

int main()
{
    scanf("%d %d", &N, &K);
    for (int n = 1; n < N; n++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        narr[a].carr.push_back(b);
        narr[b].carr.push_back(a);
    }

    step(1, 0, 0);

    std::sort(narr + 1, narr + N + 1, [](city a, city b)
              { return a.value > b.value; });

    long long ret = 0;
    for (int k = 1; k <= K; k++)
        ret += (long long)narr[k].value;

    printf("%lli\n", ret);

    return 0;
}

int step(int now, int pre, int depth)
{
    int ret = 0;

    for (int nxt : narr[now].carr)
    {
        if (nxt == pre)
            continue;

        ret += step(nxt, now, depth + 1) + 1;
    }

    narr[now].value = depth - ret;

    return ret;
}