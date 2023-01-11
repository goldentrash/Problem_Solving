#include <iostream>

int main()
{
    int M, S;
    char dummy;
    std::cin >> M >> dummy >> S;

    int btn10 = 0,
        btn30 = 0,
        btn60 = 0,
        btn600 = 0;

    int rest = M * 60 + S;

    while (rest > 0)
    {
        if (rest >= 600)
        {
            btn600++;
            rest -= 600;
        }
        else if (rest >= 60)
        {
            btn60++;
            rest -= 60;
        }
        else if (rest >= 30)
        {
            btn30++;
            rest -= 30;
        }
        else
        {
            btn10++;
            rest -= 10;
        }
    }

    btn30 = (btn30 > 0) ? btn30 : 1;

    std::cout << btn10 + btn30 + btn60 + btn600 << std::endl;

    return 0;
}