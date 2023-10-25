#include <iostream>
#include <algorithm>

#define FOR(i, st, en) for (int i = st; i < en; i++)

int C, N, M;
long long nArr[101] = {INT64_MIN},
          mArr[101] = {INT64_MIN};
int cache[101][101];

int calcLis(int ni, int mi);
void clearCache();

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N >> M;

        FOR(n, 1, N + 1)
        std::cin >> nArr[n];

        FOR(m, 1, M + 1)
        std::cin >> mArr[m];

        clearCache();
        std::cout << calcLis(0, 0) - 2 << std::endl;
    }

    return 0;
}

int calcLis(int ni, int mi)
{
    int &ret = cache[ni][mi];
    if (ret != -1)
        return ret;

    ret = 2;
    int cur = std::max(nArr[ni], mArr[mi]);

    FOR(nxt, ni + 1, N + 1)
    if (nArr[nxt] > cur)
        ret = std::max(calcLis(nxt, mi) + 1, ret);

    FOR(nxt, mi + 1, M + 1)
    if (mArr[nxt] > cur)
        ret = std::max(calcLis(ni, nxt) + 1, ret);

    return ret;
}

void clearCache()
{
    FOR(i, 0, 101)
    FOR(j, 0, 101)
    cache[i][j] = -1;
}