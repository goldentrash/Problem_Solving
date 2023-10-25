#include <iostream>

int main()
{
    int T, N;

    std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        int ret = 0;
        int now = 0;
        int pig = 0;

        std::cin >> N;
        for (int n = 0; n < N; n++)
        {
            int plan;
            std::cin >> plan;

            if (plan == 2)
            {
                if (pig == 0)
                    now = 0;
                else if (pig == 1)
                    now = 1;
                else
                {
                    now = (double)(pig - 1) / 2 + 0.8;
                    now++;
                }
            }
            else
            {
                now++;
                pig++;
            }

            if (now > ret)
                ret = now;
        }
        std::cout << ret << std::endl;
    }

    return 0;
}