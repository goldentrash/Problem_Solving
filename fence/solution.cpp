#include <iostream>
#include <algorithm>

int C, F;
int fence[20'000];

int calc(int beg, int en);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> F;
        for (int f = 0; f < F; f++)
        {
            std::cin >> fence[f];
        }
        std::cout << calc(0, F) << std::endl;
    }

    return 0;
}
int calc(int beg, int en)
{
    if (en - beg == 1)
        return fence[beg];

    int half = (beg + en) / 2;

    int height = fence[half];
    int mRet = fence[half];
    int bp = half,
        ep = half + 1;

    while (bp != beg || ep != en)
    {
        if (bp == beg)
        {
            height = (height < fence[ep]) ? height : fence[ep];
            ep++;
        }
        else if (ep == en)
        {
            bp--;
            height = (height < fence[bp]) ? height : fence[bp];
        }
        else if (fence[ep] > fence[bp - 1])
        {
            height = (height < fence[ep]) ? height : fence[ep];
            ep++;
        }
        else
        {
            bp--;
            height = (height < fence[bp]) ? height : fence[bp];
        }

        int t = (ep - bp) * height;
        mRet = (mRet > t) ? mRet : t;
    }

    return std::max({mRet, calc(beg, half), calc(half, en)});
}