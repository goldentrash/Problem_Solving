// https://codeforces.com/problemset/problem/337/d

#include <iostream>
#include <vector>

int N, M, D;
bool isP[100'001];
int wfarr[100'001];
int warr[100'001];
std::vector<int> road[100'001];

void dfs(int, int);
void calc(int, int);

int main()
{
    std::cin >> N >> M >> D;

    for (int n = 1; n <= M; n++)
    {
        int p;
        std::cin >> p;
        isP[p] = true;
    }

    for (int n = 1; n < N; n++)
    {
        int a, b;
        std::cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    warr[0] = wfarr[0] = -1;
    dfs(1, 0);
    calc(1, 0);

    int ret = 0;
    for (int n = 1; n <= N; n++)
        if (warr[n] <= D)
            ret++;

    std::cout << ret << std::endl;

    return 0;
}

void dfs(int now, int prev)
{
    if (!isP[now])
        warr[now] = wfarr[now] = -1;

    for (int nxt : road[now])
    {
        if (nxt == prev)
            continue;

        dfs(nxt, now);

        if (warr[nxt] == -1)
            continue;

        if (wfarr[now] < warr[nxt] + 1)
            wfarr[now] = warr[nxt] + 1;
        if (warr[now] < warr[nxt] + 1)
        {
            wfarr[now] = warr[now];
            warr[now] = warr[nxt] + 1;
        }
    }
}

void calc(int now, int prev)
{
    if (warr[prev] != warr[now] + 1 && warr[prev] != -1)
    {
        if (wfarr[now] < warr[prev] + 1)
            wfarr[now] = warr[prev] + 1;
        if (warr[now] < warr[prev] + 1)
        {
            wfarr[now] = warr[now];
            warr[now] = warr[prev] + 1;
        }
    }
    else if (wfarr[prev] != -1)
    {
        if (wfarr[now] < wfarr[prev] + 1)
            wfarr[now] = wfarr[prev] + 1;
        if (warr[now] < wfarr[prev] + 1)
        {
            wfarr[now] = warr[now];
            warr[now] = wfarr[prev] + 1;
        }
    }

    for (int nxt : road[now])
    {
        if (nxt == prev)
            continue;

        calc(nxt, now);
    }
}