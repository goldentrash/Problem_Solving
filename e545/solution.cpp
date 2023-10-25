// https://codeforces.com/problemset/problem/545/e
// prof. KIM
// node: 내가 어떤 가능한 경로를 취하든, 다른 node의 선택에 영향을 주지 않아!
// b449와 함께

#include <iostream>
#include <vector>
#include <queue>

struct edge
{
    int a;
    int b;
    int w;
};

struct item
{
    int to;
    long long dis;
    int edge;
    int w;
};

struct compare
{
    bool operator()(const struct item &a, const struct item &b)
    {
        if (a.dis == b.dis)
            return a.w > b.w;
        else
            return a.dis > b.dis;
    }
};

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> edgeTo[N + 1];
    struct edge edgeArr[300'001];
    for (int m = 1; m <= M; m++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edgeArr[m] = {u, v, w};
        edgeTo[u].push_back(m);
        edgeTo[v].push_back(m);
    }

    int startPoint;
    std::cin >> startPoint;

    long long fdis[N + 1];
    for (int n = 1; n <= N; n++)
        fdis[n] = 987'654'321'987'654'321;

    bool visit[N + 1] = {false};

    std::priority_queue<int> ret;
    long long totalW = 0;

    std::priority_queue<struct item,
                        std::vector<struct item>,
                        compare>
        pq;

    fdis[startPoint] = 0;
    struct item st = {.to = startPoint, .dis = 0, .edge = -1, .w = 0};
    pq.push(st);
    while (!pq.empty())
    {
        int curEdge = pq.top().edge;
        long long curDis = pq.top().dis;
        int curNode = pq.top().to;
        int curW = pq.top().w;
        pq.pop();

        if (visit[curNode])
            continue;
        visit[curNode] = true;

        if (curEdge != -1)
            ret.push(-curEdge);
        totalW += curW;

        for (int e : edgeTo[curNode])
        {
            struct edge nxtEdge = edgeArr[e];
            int nxtNode = (curNode == nxtEdge.a) ? nxtEdge.b : nxtEdge.a;
            int nxtDis = nxtEdge.w;

            // 이전 들어왔던 건 쳐내! (w가 무조건 더 클 것)
            if (fdis[nxtNode] >= curDis + nxtDis)
            {
                fdis[nxtNode] = curDis + nxtDis;
                struct item nxt = {.to = nxtNode, .dis = curDis + nxtDis, .edge = e, .w = nxtDis};
                pq.push(nxt);
            }
        }
    }

    std::cout << totalW << std::endl;
    while (!ret.empty())
    {
        std::cout << -ret.top() << " ";
        ret.pop();
    }
    std::cout << std::endl;

    return 0;
}