#include <iostream>

long long N, st, en;
long long calc(long long n, long long trg);

int main()
{
    std::cin >> N >> st >> en;

    if (N)
        std::cout << calc(N, en) - calc(N, st - 1) << std::endl;
    else
        std::cout << 0 << std::endl;

    return 0;
}

long long calc(long long n, long long trg)
{
    if (!trg)
        return 0;

    long long pivot = 1;
    while (pivot < n)
        pivot = ~(~pivot << 1);

    if (trg >= pivot)
        return n;

    pivot = (pivot >> 1) + 1;
    if (trg == pivot)
        return (n >> 1 << 1 == n) ? n >> 1 : (n >> 1) + 1;
    if (trg < pivot)
        return calc(n >> 1, trg);
    if (trg > pivot)
        return calc(n >> 1, trg - pivot) + ((n >> 1 << 1 == n) ? n >> 1 : (n >> 1) + 1);
}