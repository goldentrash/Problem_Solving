#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int flow[4][2] = {{0, 0},
                      {1, 0},
                      {1, 1},
                      {0, 1}};

    int map[256][256];

    int cnt = 0;
    for (int h = 0; h < 128; h++)
        for (int w = 0; w < 128; w++)
            for (int *pos : flow)
                map[h * 2 + pos[0]][w * 2 + pos[1]] = cnt++;

    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, M;
        std::cin >> N >> M;

        std::cout << N * M << "\n";
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                std::cout << map[n][m] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}