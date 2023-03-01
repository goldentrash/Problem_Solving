#include <iostream>
#include <iomanip>

int C, N, D, P, T;
bool map[50][50];
int cnt[50];

double ret[50][101];

void calc();

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N >> D >> P;

        for (int from = 0; from < N; from++)
        {
            cnt[from] = 0;
            for (int to = 0; to < N; to++)
            {
                std::cin >> map[from][to];
                if (map[from][to])
                    cnt[from]++;
            }
        }

        calc();

        std::cin >> T;
        for (int t = 0; t < T; t++)
        {
            int trg;
            std::cin >> trg;
            std::cout << std::fixed << std::setprecision(8) << ret[trg][D] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}

void calc()
{
    for (int n = 0; n < N; n++)
        for (int d = 0; d <= D; d++)
            ret[n][d] = 0;
    ret[P][0] = 1;

    for (int d = 1; d <= D; d++)
    {
        for (int from = 0; from < N; from++)
        {
            if (ret[from][d - 1] == 0)
                continue;

            for (int to = 0; to < N; to++)
            {
                if (!map[from][to])
                    continue;

                ret[to][d] += ret[from][d - 1] / cnt[from];
            }
        }
    }
}