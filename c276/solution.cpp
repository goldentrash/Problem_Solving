// https://codeforces.com/problemset/problem/276/c

#include <iostream>
#include <algorithm>

#define LC now << 1, l, l + r >> 1
#define RC now << 1 | 1, (l + r >> 1) + 1, r

int N;
int Q;
int seg[800'001];
int arr[200'001];
int cnt[200'001];

void update(int now, int l, int r, int s, int e)
{
    if (l > e || r < s)
        return;

    if (s <= l && r <= e)
    {
        seg[now]++;
        return;
    }

    update(LC, s, e);
    update(RC, s, e);
}

int query(int now, int l, int r, int s, int e)
{
    if (l > e || r < s)
        return 0;

    if (s <= l && r <= e)
        return seg[now];

    return query(LC, s, e) + query(RC, s, e) + seg[now];
}

int main()
{
    std::cin >> N >> Q;
    for (int n = 1; n <= N; n++)
        std::cin >> arr[n];

    for (int q = 1; q <= Q; q++)
    {
        int s, e;
        std::cin >> s >> e;
        update(1, 1, N, s, e);
    }

    for (int n = 1; n <= N; n++)
        cnt[n] = query(1, 1, N, n, n);

    std::sort(cnt + 1, cnt + N + 1);
    std::sort(arr + 1, arr + N + 1);

    long long ret = 0;
    for (int n = 1; n <= N; n++)
        ret += (long long)arr[n] * cnt[n];

    std::cout << ret << std::endl;

    return 0;
}