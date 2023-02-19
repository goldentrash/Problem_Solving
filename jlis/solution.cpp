#include <iostream>
#include <algorithm>

int C, N, M;
int nArr[100], mArr[100];
long long merged[201] = {INT64_MIN};
int cache[201];
int ans = 0;

void merge(int nc, int mc);
int calcLis(int idx);
void clearCache();

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N >> M;
        for (int n = 0; n < N; n++)
            std::cin >> nArr[n];
        for (int m = 0; m < M; m++)
            std::cin >> mArr[m];

        ans = 0;
        clearCache();

        merge(0, 0);
        std::cout << ans << std::endl;
    }

    return 0;
}

void merge(int nc, int mc)
{
    if (nc == N && mc == M)
    {
        calcLis(0);
        ans = std::max(cache[0] - 1, ans);
        clearCache();
        return;
    }

    if (nc != N)
    {
        merged[nc + mc + 1] = nArr[nc];
        merge(nc + 1, mc);
    }

    if (mc != M)
    {
        merged[nc + mc + 1] = mArr[mc];
        merge(nc, mc + 1);
    }
}

int calcLis(int idx)
{
    int &ret = cache[idx];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int nxt = idx + 1; nxt <= N + M; nxt++)
    {
        if (merged[nxt] > merged[idx])
            ret = std::max(calcLis(nxt) + 1, ret);
    }
    return ret;
}

void clearCache()
{
    for (int i = 0; i < 201; i++)
        cache[i] = -1;
}