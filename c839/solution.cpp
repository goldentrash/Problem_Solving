#include <iostream>
#include <iomanip>
#include <list>

int N;
std::list<int> carr[100'001];
bool visit[100'001];

double dfs(int c);

int main()
{
    std::cin >> N;

    for (int n = 1; n < N; n++)
    {
        int a, b;
        std::cin >> a >> b;
        carr[a].push_back(b);
        carr[b].push_back(a);
    }

    visit[1] = true;
    std::cout << std::setprecision(10) << dfs(1) << std::endl;

    return 0;
}

double dfs(int c)
{
    int cnt = 0;
    double total = 0.0;
    for (int nxt : carr[c])
    {
        if (visit[nxt])
            continue;

        visit[nxt] = true;
        total += dfs(nxt) + 1;
        visit[nxt] = false;
        cnt++;
    }
    if (cnt)
        return total / cnt;
    else
        return 0;
}