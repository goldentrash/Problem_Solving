#include <iostream>

int main()
{
    int C, N, L;
    int *nums;

    std::cin >> C;

    for (int i = 0; i < C; i++)
    {
        std::cin >> N >> L;
        nums = new int[N];

        int totalSum = 0;
        for (int j = 0; j < N; j++)
        {
            std::cin >> nums[j];
            totalSum += nums[j];
        }

        double ans = 100;
        for (int j = 0; j <= N - L; j++)
        {
            int sum = totalSum;
            for (int k = 0; k < j; k++)
            {
                sum -= nums[k];
            }

            ans = (ans < (double)sum / (N - j)) ? ans : (double)sum / (N - j);

            for (int k = N - 1; k >= L + j; k--)
            {
                sum -= nums[k];
                ans = (ans < (double)sum / (k - j)) ? ans : (double)sum / (k - j);
            }
        }

        std::cout.setf(std::ios::fixed);
        std::cout.precision(10);
        std::cout << ans << std::endl;

        delete[] nums;
    }
}