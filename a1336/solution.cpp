#include <iostream>
#include <list>
#include <algorithm>

struct city
{
    int child;
    int depth;
    std::list<int> carr;
};

int N, K;
city narr[200'001];

void step(int now, int pre);

int main()
{
    std::cin >> N >> K;
    for (int n = 1; n < N; n++)
    {
        int a, b;
        std::cin >> a >> b;

        narr[a].carr.push_back(b);
        narr[b].carr.push_back(a);
    }

    narr[0].depth = -1;
    step(1, 0);

    std::sort(narr + 1, narr + N + 1, [](city a, city b)
              { return (a.depth - a.child) > (b.depth - b.child); });

    long long ret = 0;
    for (int k = 1; k <= K; k++)
        ret += (long long)narr[k].depth - narr[k].child;

    std::cout << ret << std::endl;

    return 0;
}

void step(int now, int pre)
{
    narr[now].depth = narr[pre].depth + 1;
    narr[now].child = 0;

    for (int nxt : narr[now].carr)
    {
        if (nxt == pre)
            continue;

        step(nxt, now);
        narr[now].child += narr[nxt].child + 1;
    }
}