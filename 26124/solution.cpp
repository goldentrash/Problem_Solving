#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

int H, W;
int ans;
std::pair<int, int> lowest;

int map[1'000][1'000];
bool checked[1'000][1'000];
std::pair<int, int> dir[4] = {std::pair(-1, 0), std::pair(1, 0), std::pair(0, -1), std::pair(0, 1)};

void calc();
bool setup(std::pair<int, int> spot);

int main()
{
    std::cin >> H >> W;

    lowest = std::pair(0, 0);
    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
        {
            std::cin >> map[h][w];
            if (map[h][w] < map[lowest.first][lowest.second])
                lowest = std::pair(h, w);
        }

    ans = 0;
    calc();
    std::cout << ans << std::endl;

    return 0;
}

void calc()
{
    // find unchecked brightest spot
    std::pair<int, int> brightest = lowest;
    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
            if (map[brightest.first][brightest.second] < map[h][w] &&
                !checked[h][w])
                brightest = std::pair(h, w);

    if (brightest == lowest || map[brightest.first][brightest.second] == 0) // if all lights already setted up
        return;

    // setup light
    if (setup(brightest))
        calc(); // repeat if setup was successful
}

bool setup(std::pair<int, int> spot)
{
    std::pair<int, int> del(-1, -1);
    int light = map[spot.first][spot.second];
    int cnt = 0;

    bool visit[1'000][1'000];
    std::memset(visit, 0, H * W * sizeof(bool));

    std::queue<std::pair<int, int>> q;
    q.push(spot);
    visit[spot.first][spot.second] = true;
    q.push(del);

    while (!q.empty())
    {
        std::pair now = q.front();
        q.pop();

        if (now == del)
        {
            if (q.empty())
                break;
            q.push(del);
            cnt++;

            if (cnt == light)
                break;
            else
                continue;
        }

        if (map[now.first][now.second] < light - cnt)
        {
            ans = -1;
            return false;
        }
        else if (map[now.first][now.second] == light - cnt)
            checked[now.first][now.second] = true;

        for (std::pair<int, int> d : dir)
        {
            std::pair next(now.first + d.first, now.second + d.second);

            if (next.first < 0 || next.first == H || next.second < 0 || next.second == W ||
                visit[next.first][next.second] || map[next.first][next.second] == -1)
                continue;

            q.push(next);
            visit[next.first][next.second] = true;
        }
    }

    ans++;
    return true;
}