#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

int H, W;
int ans;

int map[1'000][1'000];
std::pair<int, int> dir[4] = {
    std::pair(-1, 0), std::pair(1, 0), std::pair(0, -1), std::pair(0, 1)};

bool isPossible();
void calc();
void setup(std::pair<int, int> spot);

int main()
{
    std::cin >> H >> W;

    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
            std::cin >> map[h][w];

    if (!isPossible())
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    ans = 0;
    calc();
    std::cout << ans << std::endl;

    return 0;
}

bool isPossible()
{
    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
        {
            if (map[h][w] == -1)
                continue;

            for (std::pair<int, int> d : dir)
            {
                std::pair next(h + d.first, w + d.second);

                if (next.first < 0 || next.first == H || next.second < 0 || next.second == W ||
                    map[next.first][next.second] == -1)
                    continue;

                if (std::abs(map[h][w] - map[next.first][next.second]) > 1)
                    return false;
            }
        }

    return true;
}

void calc()
{
    // find unchecked brightest spot
    std::pair<int, int> brightest = std::pair(0, 0);
    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
            if (map[brightest.first][brightest.second] < map[h][w])
                brightest = std::pair(h, w);

    // if all lights already setted up
    if (map[brightest.first][brightest.second] == 0)
        return;

    // setup light
    setup(brightest);
    ans++;

    // repeat until all lights setted up
    calc();
}

void setup(std::pair<int, int> spot)
{
    bool visit[H][W];
    std::memset(visit, 0, H * W * sizeof(bool));

    int light = map[spot.first][spot.second];
    int cnt = 0;

    std::queue<std::pair<int, int>> q;
    std::pair<int, int> del(-1, -1);

    q.push(spot);
    visit[spot.first][spot.second] = true;
    map[spot.first][spot.second] = 0;
    q.push(del);

    while (q.size() != 1)
    {
        std::pair now = q.front();
        q.pop();

        if (now == del)
        {
            q.push(del);
            cnt++;
            continue;
        }

        if (map[now.first][now.second] == light - cnt)
            map[now.first][now.second] = 0;

        for (std::pair<int, int> d : dir)
        {
            std::pair next(now.first + d.first, now.second + d.second);

            if (next.first < 0 || next.first == H || next.second < 0 || next.second == W ||
                map[next.first][next.second] < 1 || visit[next.first][next.second])
                continue;

            q.push(next);
            visit[next.first][next.second] = true;
        }
    }
}