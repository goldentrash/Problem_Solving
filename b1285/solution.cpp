#include <iostream>
#include <algorithm>

int T, N;
int tastiness[100'000];
long long pSum[100'001];

int main()
{
    std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        std::cin >> N;
        pSum[0] = 0;
        for (int n = 0; n < N; n++)
        {
            std::cin >> tastiness[n];
            pSum[n + 1] = tastiness[n] + pSum[n];
        }

        std::sort(tastiness, tastiness + N);

        long long adel = pSum[N] - tastiness[0];
        for (int n = 1; n < N; n++)
        {
            if (tastiness[n] < 0)
                adel -= tastiness[n];
        }

        std::cout << ((pSum[N] > adel) ? "YES" : "NO") << std::endl;
    }

    return 0;
}