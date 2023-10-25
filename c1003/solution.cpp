#include <iostream>
#include <iomanip>

int N, K;
int temp[5'000];
int pSum[5'001];
double ret;

int main()
{
    std::cin >> N >> K;
    pSum[0] = 0;
    for (int n = 0; n < N; n++)
    {
        std::cin >> temp[n];
        pSum[n + 1] = temp[n] + pSum[n];
    }

    ret = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = i + K; j <= N; j++)
        {
            ret = std::max(ret, (double)(pSum[j] - pSum[i]) / (j - i));
        }
    }

    std::cout << std::fixed << std::setprecision(7) << ret << std::endl;

    return 0;
}