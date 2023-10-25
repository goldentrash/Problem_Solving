#include <iostream>
#include <cstring>

int main()
{
    int N;
    std::cin >> N;

    int cnt[5];
    std::memset(cnt, 0, 5 * sizeof(int));

    for (int n = 0; n < N; n++)
    {
        int temp;
        std::cin >> temp;

        cnt[temp]++;
    }

    int ans = cnt[4] + cnt[3] + cnt[2] / 2;

    (cnt[3] < cnt[1]) ? cnt[1] -= cnt[3] : cnt[1] = 0;

    if (cnt[2] >> 1 << 1 != cnt[2])
        cnt[1] += 2;

    ans += cnt[1] / 4;
    if (cnt[1] % 4 != 0)
        ans++;

    std::cout << ans << std::endl;
}