// https://codeforces.com/problemset/problem/707/b

#include <iostream>
#include <vector>

int main()
{
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> connected[N + 1];
    for (int m = 1; m <= M; m++)
    {
        int i, j, k;
        std::cin >> i >> j >> k;
        std::pair<int, int> load;
        load.first = j;
        load.second = k;
        connected[i].push_back(load);
        load.first = i;
        connected[j].push_back(load);
    }

    std::vector<int> storage;
    bool isStorage[N + 1] = {false};
    for (int k = 1; k <= K; k++)
    {
        int s;
        std::cin >> s;
        storage.push_back(s);
        isStorage[s] = true;
    }

    int len = -1;
    for (int s : storage)
        for (std::pair<int, int> t : connected[s])
        {
            if (isStorage[t.first])
                continue;

            if (len == -1 || t.second < len)
                len = t.second;
        }

    std::cout << len << std::endl;
}