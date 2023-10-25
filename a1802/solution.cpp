#include <iostream>

int T, N;
std::pair<int, int> likes[101];

int main()
{
    std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        std::cin >> N;
        for (int n = 1; n <= N; n++)
            likes[n] = std::pair(0, 0);

        for (int n = 0; n < N; n++)
        {
            int t;
            std::cin >> t;
            (t > 0)
                ? likes[t].first++
                : likes[-1 * t].second++;
        }

        int pCnt = 0;
        int lCnt = 0;
        int dCnt = 0;
        int fCnt = 0;
        for (int n = 1; n <= N; n++)
        {
            lCnt += likes[n].first;
            dCnt += likes[n].second;
            if (likes[n].first)
                pCnt++;
            if (likes[n].first > likes[n].second)
                fCnt++;
        }

        for (int i = 1; i <= pCnt; i++)
            std::cout << i << " ";
        for (int i = 0; i < lCnt - pCnt; i++)
            std::cout << pCnt - 1 << " " << pCnt << " ";
        for (int i = pCnt - 1; i >= fCnt; i--)
            std::cout << i << " ";
        std::cout << std::endl;

        for (int i = 0; i < dCnt; i++)
            std::cout << 1 << " " << 0 << " ";
        for (int i = 1; i <= fCnt; i++)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}