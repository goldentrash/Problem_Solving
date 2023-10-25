#include <iostream>
#include <algorithm>

int N;
int carr[100'000];
std::string sarr[100'000];
std::string rsarr[100'000];
long long cache[2][100'000];

const long long INF = 987'654'321'987'654'321;

int main()
{
    std::cin >> N;
    for (int n = 0; n < N; n++)
        std::cin >> carr[n];
    for (int n = 0; n < N; n++)
    {
        std::cin >> sarr[n];
        rsarr[n] = sarr[n];
        std::reverse(rsarr[n].begin(), rsarr[n].end());
    }

    cache[0][0] = 0;
    cache[1][0] = carr[0];
    for (int n = 1; n < N; n++)
    {
        cache[0][n] = INF;
        if (cache[0][n - 1] != -1 && std::less_equal<std::string>()(sarr[n - 1], sarr[n]))
            cache[0][n] = std::min(cache[0][n - 1], cache[0][n]);
        if (cache[1][n - 1] != -1 && std::less_equal<std::string>()(rsarr[n - 1], sarr[n]))
            cache[0][n] = std::min(cache[1][n - 1], cache[0][n]);
        if (cache[0][n] == INF)
            cache[0][n] = -1;

        cache[1][n] = INF;
        if (cache[0][n - 1] != -1 && std::less_equal<std::string>()(sarr[n - 1], rsarr[n]))
            cache[1][n] = std::min(cache[0][n - 1] + carr[n], cache[1][n]);
        if (cache[1][n - 1] != -1 && std::less_equal<std::string>()(rsarr[n - 1], rsarr[n]))
            cache[1][n] = std::min(cache[1][n - 1] + carr[n], cache[1][n]);
        if (cache[1][n] == INF)
            cache[1][n] = -1;
    }

    if (cache[0][N - 1] == -1)
        std::cout << cache[1][N - 1] << std::endl;
    else if (cache[1][N - 1] == -1)
        std::cout << cache[0][N - 1] << std::endl;
    else
        std::cout << std::min(cache[0][N - 1], cache[1][N - 1]) << std::endl;

    return 0;
}
