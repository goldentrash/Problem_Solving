// https://codeforces.com/problemset/problem/20/c

#include <iostream>
#include <vector>
#include <queue>

struct compare
{
    bool operator()(std::pair<int, long long> &a,
                    std::pair<int, long long> &b)
    {
        return a.second > b.second;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> to[N + 1];
    for (int m = 1; m <= M; m++)
    {
        int a, b, w;
        std::cin >> a >> b >> w;
        to[a].push_back(std::make_pair(b, w));
        to[b].push_back(std::make_pair(a, w));
    }

    std::priority_queue<std::pair<int, long long>,
                        std::vector<std::pair<int, long long>>,
                        compare>
        pq;

    long long dis[N + 1];
    int ahead[N + 1];
    for (int n = 1; n <= N; n++)
    {
        dis[n] = 321'987'654'321;
        ahead[n] = -1;
    }

    dis[1] = 0;
    ahead[1] = 1;
    pq.push(std::make_pair(1, 0));

    while (!pq.empty())
    {
        int now = pq.top().first;
        long long now_dis = pq.top().second;
        pq.pop();

        if (dis[now] < now_dis)
            continue;

        if (now == N)
            break;

        for (const std::pair<int, int> &road : to[now])
        {
            int next = road.first;
            int next_dis = road.second;

            if (dis[next] > now_dis + next_dis)
            {
                dis[next] = now_dis + next_dis;
                ahead[next] = now;
                pq.push(std::make_pair(next, now_dis + next_dis));
            }
        }
    }

    if (ahead[N] == -1)
    {
        std::cout << -1;
        return 0;
    }

    std::vector<int> ret;
    int cur = N;
    ret.push_back(N);
    while (cur != 1)
    {
        cur = ahead[cur];
        ret.push_back(cur);
    }

    for (int i = ret.size() - 1; i >= 0; i--)
        std::cout << ret[i] << " ";

    return 0;
}