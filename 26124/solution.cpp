#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <bits/stdc++.h>

int H, W;
int ans;

int map[1'000][1'000];
std::pair<int, int> dir[4] = {
    std::pair(-1, 0), std::pair(1, 0), std::pair(0, -1), std::pair(0, 1)};

bool isPossible();
void setup(std::pair<int, int> spot);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

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
    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
        {
            if (map[h][w] == 0)
                continue;

            if (!(h + 1 != H && map[h + 1][w] >= map[h][w]) &&
                !(w + 1 != W && map[h][w + 1] >= map[h][w]))
                ans++;

            setup(std::pair(h, w));
        }
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

        if (map[now.first][now.second] > light - cnt)
            continue;

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