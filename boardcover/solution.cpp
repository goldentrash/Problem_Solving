#include <iostream>

int C, H, W;
char map[20][20];

// 로직과 데이터 분리
const char shape[4][2][2] = {
    {{0, 1},
     {1, 0}},
    {{0, 1},
     {1, 1}},
    {{1, 0},
     {1, 1}},
    {{1, 0},
     {1, -1}}};

int cnt;
int rest;

void calc();
bool canPlace(int h, int w, int s);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> H >> W;
        cnt = 0;
        rest = 0;
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                std::cin >> map[h][w];
                if (map[h][w] == '.')
                    rest++;
            }
        }

        // 특이상황 조기 발견으로 최적화
        if (rest % 3 == 0)
            calc();

        std::cout << cnt << std::endl;
    }

    return 0;
}

void calc()
{
    if (rest == 0)
    {
        cnt++;
        return;
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (map[h][w] == '#')
                continue;

            for (int i = 0; i < 4; i++)
            {
                if (canPlace(h, w, i))
                {
                    map[h][w] = '#';
                    map[h + shape[i][0][0]][w + shape[i][0][1]] = '#';
                    map[h + shape[i][1][0]][w + shape[i][1][1]] = '#';

                    rest -= 3;
                    calc();
                    rest += 3;

                    map[h][w] = '.';
                    map[h + shape[i][0][0]][w + shape[i][0][1]] = '.';
                    map[h + shape[i][1][0]][w + shape[i][1][1]] = '.';
                }
            }

            // 중요!!
            // 앞에서부터 빈 공간을 채우면서 진행,
            // 한 번씩 다 채워봤다면, 재귀를 종요해야 함.
            // return문이 없다면, 빈 공간을 남긴채로 다음 공간으로 계속 이동
            return;
        }
    }
}

bool canPlace(int h, int w, int s)
{
    if (h < 0 || h >= H)
        return false;
    if (w < 0 || w >= W)
        return false;
    if (map[h][w] == '#')
        return false;

    h += shape[s][0][0];
    w += shape[s][0][1];

    if (h < 0 || h >= H)
        return false;
    if (w < 0 || w >= W)
        return false;
    if (map[h][w] == '#')
        return false;

    h -= shape[s][0][0];
    w -= shape[s][0][1];

    h += shape[s][1][0];
    w += shape[s][1][1];

    if (h < 0 || h >= H)
        return false;
    if (w < 0 || w >= W)
        return false;
    if (map[h][w] == '#')
        return false;

    return true;
}