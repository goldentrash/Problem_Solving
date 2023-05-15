// https://codeforces.com/problemset/problem/52/c

// tree structure
// leaf가 입력 value
// 범위 더하기는 중간 node에 더하기
// inc도 lgn, rmq도 lgn

#include <iostream>
#include <sstream>

int arr[200'001];
long long seg[200'000 * 4 + 1];
long long lazy[200'000 * 4 + 1];

void mkSeg(int idx, int st, int en)
{
    if (st == en)
    {
        seg[idx] = arr[st];
        return;
    }

    int mid = (st + en) >> 1;

    mkSeg(idx << 1, st, mid);
    mkSeg((idx << 1) + 1, mid + 1, en);

    seg[idx] = std::min(seg[idx << 1], seg[(idx << 1) + 1]);
}

long long getMin(int idx, int l, int r, int st, int en)
{
    if (l == st && r == en)
        return seg[idx];

    int m = (l + r) >> 1;
    if (en <= m)
        return getMin(idx << 1, l, m, st, en) + lazy[idx];
    else if (st > m)
        return getMin((idx << 1) + 1, m + 1, r, st, en) + lazy[idx];
    else
        return std::min(getMin(idx << 1, l, m, st, m), getMin((idx << 1) + 1, m + 1, r, m + 1, en)) + lazy[idx];
}

void update(int idx, int l, int r, int st, int en, int value)
{
    if (l == st && r == en)
    {
        lazy[idx] += value;
        seg[idx] += value;
        return;
    }

    int m = (l + r) >> 1;
    if (en <= m)
        update(idx << 1, l, m, st, en, value);
    else if (st > m)
        update((idx << 1) + 1, m + 1, r, st, en, value);
    else
    {
        update(idx << 1, l, m, st, m, value);
        update((idx << 1) + 1, m + 1, r, m + 1, en, value);
    }

    seg[idx] = std::min(seg[idx << 1], seg[(idx << 1) + 1]) + lazy[idx];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    for (int n = 1; n <= N; n++)
        std::cin >> arr[n];

    mkSeg(1, 1, N);

    int M;
    std::cin >> M;
    std::cin.ignore();
    for (int m = 0; m < M; m++)
    {
        std::string line;
        std::getline(std::cin, line);

        std::stringstream sin;
        sin.str(line);

        int arg[3];
        int argc = 0;
        while (sin >> arg[argc])
            argc++;

        arg[0]++;
        arg[1]++;

        if (argc == 2)
            if (arg[0] <= arg[1])
                std::cout << getMin(1, 1, N, arg[0], arg[1]) << std::endl;
            else
                std::cout << std::min(getMin(1, 1, N, 1, arg[1]), getMin(1, 1, N, arg[0], N)) << std::endl;
        else if (arg[0] <= arg[1])
            update(1, 1, N, arg[0], arg[1], arg[2]);
        else
        {
            update(1, 1, N, 1, arg[1], arg[2]);
            update(1, 1, N, arg[0], N, arg[2]);
        }
    }

    return 0;
}