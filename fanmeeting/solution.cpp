#include <iostream>
#include <string>

int C, N, M;
std::string member,
    fan;

int calc(int beg, int en);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> member;
        std::cin >> fan;
        M = member.length();
        N = fan.length();

        std::cout << calc(0, N) << std::endl;
    }
    return 0;
}

int calc(int beg, int en)
{
    if (en - beg < M)
        return 0;

    int half = (beg + en) / 2;
    int mRet = 0;
    for (int b = half - M + 1; b < half; b++)
    {
        if (b < beg)
            continue;
        if (b + M > en)
            break;

        for (int m = 0; m < M; m++)
        {
            if (member[m] == 'M' && fan[b + m] == 'M')
                goto NEXT;
        }

        mRet++;
    NEXT:
        continue;
    }

    return calc(beg, half) + calc(half, en) + mRet;
}