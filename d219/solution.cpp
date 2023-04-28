// https://codeforces.com/problemset/problem/219/d
#include <iostream>
#include <vector>
#include <algorithm>

int max = 0;
int r = 0;
std::vector<int> ret;
std::vector<int> to[200'001];
std::vector<int> from[200'001];

void dfs(int, int, int);

int main()
{
    int N;
    std::cin >> N;
    for (int n = 1; n < N; n++)
    {
        int s, t;
        std::cin >> s >> t;

        to[t].push_back(s);
        from[s].push_back(t);
    }

    dfs(1, 0, 0);

    std::sort(ret.begin(), ret.end());

    std::cout << r - max << std::endl;

    for (int c : ret)
        std::cout << c << " ";
    std::cout << std::endl;

    return 0;
}

void dfs(int now, int prev, int w)
{
    if (max < w)
    {
        max = w;
        ret.clear();
    }

    if (max == w)
        ret.push_back(now);

    for (int nxt : from[now])
    {
        if (nxt == prev)
            continue;

        dfs(nxt, now, w - 1);
    }

    for (int nxt : to[now])
    {
        if (nxt == prev)
            continue;
        r++;
        dfs(nxt, now, w + 1);
    }
}