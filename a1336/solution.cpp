#include <iostream>
#include <list>
#include <algorithm>

int N, K;
int varr[200'001];
std::list<int> rarr[200'001];

int step(int now, int pre, int depth);

int main()
{
    scanf("%d %d", &N, &K);
    for (int n = 1; n < N; n++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        rarr[a].push_back(b);
        rarr[b].push_back(a);
    }

    step(1, 0, 0);

    std::sort(varr + 1, varr + N + 1, std::greater<int>());

    long long ret = 0;
    if ((N >> 2) > K)
        for (int k = 1; k <= K; k++)
            ret += (long long)varr[k];
    else
        for (int k = K + 1; k <= N; k++)
            ret -= (long long)varr[k];

    printf("%lli\n", ret);

    return 0;
}

int step(int now, int pre, int depth)
{
    int ret = 0;

    for (int nxt : rarr[now])
    {
        if (nxt == pre)
            continue;

        ret += step(nxt, now, depth + 1) + 1;
    }

    varr[now] = depth - ret;

    return ret;
}