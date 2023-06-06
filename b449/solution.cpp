// https://codeforces.com/problemset/problem/449/b
// prof. KIM
// "나중 들어온걸 쳐내!"
// 동일한 len이 들어왔을 때, 어떤 기준으로 교체 여부를 결정하는가
// e545와 함께

#include <iostream>
#include <queue>
#include <vector>

struct way
{
    int to;
    int w;
    bool isTrain;
};

struct compare
{
    bool operator()(const std::pair<struct way, long long> &a, const std::pair<struct way, long long> &b)
    {
        if (a.second == b.second)
            return a.first.isTrain;
        else
            return a.second > b.second;
    }
};

int main()
{
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<struct way> edgeTo[N + 1];
    for (int m = 1; m <= M; m++)
    {
        int u, v, x;
        std::cin >> u >> v >> x;
        edgeTo[u].push_back({v, x, false});
        edgeTo[v].push_back({u, x, false});
    }

    for (int k = 1; k <= K; k++)
    {
        int s, y;
        std::cin >> s >> y;
        edgeTo[1].push_back({s, y, true});
    }

    bool visit[N + 1] = {false};
    long long fdis[N + 1];
    for (int n = 1; n <= N; n++)
        fdis[n] = 987'654'321'987'654'321;

    std::priority_queue<std::pair<struct way, long long>,
                        std::vector<std::pair<struct way, long long>>,
                        compare>
        pq;
    pq.push(std::make_pair<struct way, long long>({1, -1, false}, 0));
    fdis[1] = 0;
    int ret = K;
    while (!pq.empty())
    {
        int cur = pq.top().first.to;
        bool isTrain = pq.top().first.isTrain;
        long long cdis = pq.top().second;
        pq.pop();

        if (visit[cur])
            continue;
        visit[cur] = true;

        if (isTrain)
            ret--;

        for (struct way edge : edgeTo[cur])
        {
            int nxt = edge.to;
            int ndis = edge.w;
            bool isTrain = edge.isTrain;

            if (!visit[nxt] && fdis[nxt] >= cdis + ndis)
            {
                pq.push(std::make_pair<struct way, long long>({nxt, -1, isTrain}, cdis + ndis));
                fdis[nxt] = cdis + ndis;
            }
        }
    }

    std::cout << ret;

    return 0;
}