#include <iostream>
#include <vector>

int C;
int cnt;
int map[16];

// 원래 2차원(2중첩...?) 벡터로 하려고 했는데 ref가 이상하게 잡혀서 관 둠
std::vector<int> s0 = {0, 1, 2};
std::vector<int> s1 = {3, 7, 9, 11};
std::vector<int> s2 = {4, 10, 14, 15};
std::vector<int> s3 = {0, 4, 5, 6, 7};
std::vector<int> s4 = {6, 7, 8, 10, 12};
std::vector<int> s5 = {0, 2, 14, 15};
std::vector<int> s6 = {3, 14, 15};
std::vector<int> s7 = {4, 5, 7, 14, 15};
std::vector<int> s8 = {1, 2, 3, 4, 5};
std::vector<int> s9 = {3, 4, 5, 9, 13};

void push(std::vector<int> s);
void correct(std::vector<int> s, std::vector<int> m);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        cnt = 0;
        for (int i = 0; i < 16; i++)
            std::cin >> map[i];

        try
        {
            correct(s4, {8, 12});
            correct(s3, {6});
            correct(s2, {10});
            correct(s1, {11});
            correct(s9, {9, 13});
            correct(s7, {7});
            correct(s8, {4, 5});
            correct(s0, {1});
            correct(s5, {0, 2});
            correct(s6, {3, 14, 15});

            std::cout << cnt << std::endl;
        }
        catch (int err)
        {
            std::cout << err << std::endl;
        }
    }

    return 0;
}

void correct(std::vector<int> s, std::vector<int> m)
{
    for (int e : m)
        if (map[e] != map[m[0]])
            throw -1;

    while (map[m[0]] != 12)
        push(s);
}

void push(std::vector<int> s)
{
    for (int m : s)
    {
        if (map[m] == 12)
            map[m] = 3;
        else
            map[m] += 3;
    }
    cnt++;
}