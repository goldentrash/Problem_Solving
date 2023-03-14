#include <iostream>

int main()
{
    int two, three, five, six;
    int cnt256, cnt32;
    std::cin >> two >> three >> five >> six;

    cnt256 = (five < six) ? five : six;
    cnt256 = (cnt256 < two) ? cnt256 : two;

    cnt32 = (two - cnt256 < three) ? two - cnt256 : three;

    std::cout << (long long)cnt256 * 256 + (long long)cnt32 * 32 << std::endl;

    return 0;
}