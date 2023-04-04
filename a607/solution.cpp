#include <iostream>
#include <algorithm>

int N;
std::pair<int, int> arr[1'000'001];
int cache[1'000'001];

int bs(int trg, int st, int en);

int main()
{
    std::cin >> N;
    for (int n = 1; n <= N; n++)
        std::cin >> arr[n].first >> arr[n].second;

    std::sort(arr + 1, arr + N + 1);

    cache[0] = 0;
    for (int n = 1; n <= N; n++)
    {
        int tmp = bs(arr[n].first - arr[n].second - 1, 1, n);
        cache[n] = cache[tmp] + (n - tmp - 1);
    }

    int ret = 987'654'321;
    for (int n = 1; n <= N; n++)
        ret = std::min(ret, cache[n] + (N - n));

    std::cout << ret << std::endl;

    return 0;
}

int bs(int trg, int st, int en)
{
    if (st + 1 == en)
        return (trg >= arr[st].first) ? st : st - 1;
    if (st == en)
        return st - 1;

    int mid = (st + en) / 2;

    if (trg == arr[mid].first)
        return mid;

    if (trg < arr[mid].first)
        return bs(trg, st, mid);
    else
        return bs(trg, mid + 1, en);
}