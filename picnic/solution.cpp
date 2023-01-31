#include <iostream>

int C, N, M;
int cnt;
int rest;
bool edge[10][10];
bool hasPair[10];

void calc();

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> N >> M;

        // init
        for (int n = 0; n < N; n++)
        {
            for (int j = 0; j < N; j++)
            {
                edge[n][j] = false;
            }
            hasPair[n] = false;
        }

        for (int m = 0; m < M; m++)
        {
            int a, b;
            std::cin >> a >> b;
            edge[a][b] = edge[b][a] = true;
        }

        cnt = 0;
        rest = N;

        calc();

        std::cout << cnt << std::endl;
    }

    return 0;
}

void calc()
{
    if (rest == 0) // base
    {
        cnt++;
        return;
    }

    int a = -1;
    while (++a < N)
        if (!hasPair[a])
            break;

    hasPair[a] = true;
    rest--;

    int b = a;
    bool *isConnedted = edge[a];
    while (++b < N)
    {
        if (hasPair[b] || !isConnedted[b])
            continue;

        hasPair[b] = true;
        rest--;

        calc();

        hasPair[b] = false;
        rest++;
    }

    hasPair[a] = false;
    rest++;
}