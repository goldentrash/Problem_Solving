#include <iostream>
#include <algorithm>

int C;
std::string nums;

int cache[10'000];

int calc(int idx);
int pattern(int idx, int len);
void clearCache();

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> nums;
        clearCache();
        std::cout << calc(0) << std::endl;
    }

    return 0;
}

int calc(int idx)
{
    if (idx == nums.length())
        return 0;
    if (idx > nums.length())
        return 987'654'321;

    int &ret = cache[idx];
    if (ret != -1)
        return ret;

    ret = std::min({calc(idx + 3) + pattern(idx, 3),
                    calc(idx + 4) + pattern(idx, 4),
                    calc(idx + 5) + pattern(idx, 5)});
    return ret;
}

void clearCache()
{
    for (int i = 0; i < 10'000; i++)
        cache[i] = -1;
}

int pattern(int idx, int len)
{
    bool isAriths = true;

    for (int i = idx + 2; i < idx + len; i++)
        if (nums[i] - nums[i - 1] != nums[i - 1] - nums[i - 2])
            isAriths = false;

    if (isAriths)
    {
        if (nums[idx] == nums[idx + 1])
            return 1;
        else if (abs(nums[idx] - nums[idx + 1]) == 1)
            return 2;
        else
            return 5;
    }

    if (nums[idx] == nums[idx + 2])
    {
        if (len == 3)
            return 4;

        if (nums[idx + 1] == nums[idx + 3])
        {
            if (len == 4)
                return 4;

            if (nums[idx + 4] == nums[idx])
                return 4;
        }
    }

    return 10;
}