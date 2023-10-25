#include <iostream>
#include <algorithm>

int N;
long long dp_max[10];
long long dp_min[10];
long long n[10];
char o[9];

void swap(long long &a, long long &b);
long long operate(long long a, long long b, char op);

int main()
{
    std::cin >> N;
    N = N / 2 + 1;
    for (int i = 0; i < N - 1; i++)
        std::cin >> n[i] >> o[i];
    std::cin >> n[N - 1];

    if (N == 1)
        return n[0];

    // base
    dp_max[0] = dp_min[0] = n[0];
    dp_max[1] = dp_min[1] = operate(n[0], n[1], o[0]);

    // step
    for (int i = 2; i < N; i++)
    {
        long long noParnth_max = operate(dp_max[i - 1], n[i], o[i - 1]);
        long long noParnth_min = operate(dp_min[i - 1], n[i], o[i - 1]);

        long long curParnth = operate(n[i - 1], n[i], o[i - 1]);
        long long parnth_max = operate(dp_max[i - 2], curParnth, o[i - 2]);
        long long parnth_min = operate(dp_min[i - 2], curParnth, o[i - 2]);
        // IF curParenthese < 0 && o[i - 2] == '*'
        if (parnth_max < parnth_min)
            swap(parnth_max, parnth_min);

        dp_max[i] = std::max(noParnth_max, parnth_max);
        dp_min[i] = std::min(noParnth_min, parnth_min);
    }

    std::cout << dp_max[N - 1] << std::endl;

    return 0;
}

void swap(long long &a, long long &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

long long operate(long long a, long long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        throw;
    }
}