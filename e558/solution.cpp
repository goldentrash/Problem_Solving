// https://codeforces.com/problemset/problem/558/e

// 정렬 한계는 NlogN이다.
// 하지만, 문자의 개수가 한정되어 있다면 더 빠르게 가능하다
// 26개(알파벳 당 하나)의 seg tree를 만들고,
// 각각의 범위에 해당 알파벳이 몇 개 있는지 기록해보자

#define LC now << 1, l, l + r >> 1
#define RC now << 1 | 1, (l + r >> 1) + 1, r

#include <iostream>

int N; // 100'000
int Q; // 50'000
char input[100'001];
int seg[26][400'001];
int lazy[26][400'001];

void push_down(int c, int now, int l, int r)
{
    if (lazy[c][now] == -1)
        return;

    if (lazy[c][now] == 0)
        seg[c][now << 1] = seg[c][now << 1 | 1] = 0;
    else
    {
        seg[c][now << 1] = (l + r >> 1) - l + 1;
        seg[c][now << 1 | 1] = r - (l + r >> 1);
    }

    lazy[c][now << 1] = lazy[c][now << 1 | 1] = lazy[c][now];
    lazy[c][now] = -1;
};

void push_up(int c, int now, int l, int r)
{
    seg[c][now] = seg[c][now << 1] + seg[c][now << 1 | 1];
}

void make(int now, int l, int r)
{
    for (int c = 0; c < 26; c++)
        lazy[c][now] = -1;

    if (l == r)
    {
        seg[input[l] - 'a'][now] = 1;
        return;
    }

    make(LC);
    make(RC);

    for (int c = 0; c < 26; c++)
        seg[c][now] = seg[c][now << 1] + seg[c][now << 1 | 1];
}

int query(int c, int now, int l, int r, int s, int e)
{
    if (l > e || r < s)
        return 0;

    if (s <= l && r <= e)
        return seg[c][now];

    push_down(c, now, l, r);

    return query(c, LC, s, e) + query(c, RC, s, e);
}

void update(int c, int now, int l, int r, int s, int e, int to)
{
    if (l > e || r < s)
        return;

    if (s <= l && r <= e)
    {
        lazy[c][now] = to;
        seg[c][now] = (to == 0) ? 0 : r - l + 1;
        return;
    }

    push_down(c, now, l, r);

    update(c, LC, s, e, to);
    update(c, RC, s, e, to);

    push_up(c, now, l, r);
}

void printRet()
{
    for (int n = 1; n <= N; n++)
        for (int c = 0; c < 26; c++)
            if (query(c, 1, 1, N, n, n))
            {
                std::cout << (char)('a' + c);
                break;
            }
}

int main()
{
    std::cin >> N >> Q;
    std::cin >> input + 1;

    make(1, 1, N);

    for (int q = 1; q <= Q; q++)
    {
        int s, e, o;
        std::cin >> s >> e >> o;
        int cnt[26];
        int cursor = 0;
        for (int c = 0; c < 26; c++)
        {
            cnt[c] = query(c, 1, 1, N, s, e);
            update(c, 1, 1, N, s, e, 0);

            if (o == 1)
                update(c, 1, 1, N, s + cursor, s + cursor + cnt[c] - 1, 1);
            else
                update(c, 1, 1, N, e - cursor - cnt[c] + 1, e - cursor, 1);
            cursor += cnt[c];
        }
    }

    printRet();

    return 0;
}