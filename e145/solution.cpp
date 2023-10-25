// https://codeforces.com/problemset/problem/145/e

// 구간별
// 중간 노드에 저장
// 1.
// 전부 4인 가장 큰 길이
// 전부 7인 가장 큰 길이
// 4->7인 가장 큰 길이
// 2.
// 구간이 뒤집혔는지 그대론지 저장

#include <iostream>
#include <cstring>
#include <algorithm>

struct seg
{
    int v4;
    int v7;
    int v47;
    int v74;
};

int N;
int M;
char input[1'000'001];
struct seg tree[4'000'001];
bool lazy[4'000'001];

void compos(struct seg &dest, const struct seg &s1, const struct seg &s2)
{
    dest.v4 = s1.v4 + s2.v4;
    dest.v7 = s1.v7 + s2.v7;
    dest.v47 = std::max({s1.v4 + s2.v7, s1.v47 + s2.v7, s1.v4 + s2.v47});
    dest.v74 = std::max({s1.v7 + s2.v4, s1.v74 + s2.v4, s1.v7 + s2.v74});
}

void mkSeg(int i, int l, int r)
{
    if (l == r)
    {
        tree[i].v4 = input[l] == '4';
        tree[i].v7 = input[l] == '7';
        tree[i].v47 = tree[i].v74 = 1;
        return;
    }

    int m = (l + r) >> 1;
    int lc = i << 1;
    int rc = (i << 1) + 1;

    mkSeg(lc, l, m);
    mkSeg(rc, m + 1, r);

    compos(tree[i], tree[lc], tree[rc]);
}

void update(int now, int lc, int rc)
{
    if (lazy[now])
    {
        int tmp;
        tmp = tree[now].v4;
        tree[now].v4 = tree[now].v7;
        tree[now].v7 = tmp;

        tmp = tree[now].v47;
        tree[now].v47 = tree[now].v74;
        tree[now].v74 = tmp;

        if (lc < 4'000'001)
        {
            lazy[lc] = !lazy[lc];
            lazy[rc] = !lazy[rc];
        }
        lazy[now] = false;
    }
}

void flip(int i, int l, int r, int st, int en)
{
    int m = (l + r) >> 1;
    int lc = i << 1;
    int rc = (i << 1) + 1;

    update(i, lc, rc);

    if (st > r || en < l)
        return;

    if (st <= l && r <= en)
    {
        lazy[i] = true;
        update(i, lc, rc);
        return;
    }

    flip(lc, l, m, st, en);
    flip(rc, m + 1, r, st, en);

    compos(tree[i], tree[lc], tree[rc]);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    for (int n = 1; n <= N; n++)
        std::cin >> input[n];

    mkSeg(1, 1, N);

    char cmd[10];
    for (int m = 0; m < M; m++)
    {
        std::cin >> cmd;
        if (!strcmp(cmd, "count"))
            std::cout << tree[1].v47 << std::endl;
        else
        {
            int s, e;
            std::cin >> s >> e;
            flip(1, 1, N, s, e);
        }
    }

    return 0;
}