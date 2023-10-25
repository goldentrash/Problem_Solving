#include <fstream>
#include <algorithm>
#include <iostream>
#include <cstdlib>

const int SIZE_DISK = 500;
const int SIZE_MEMORY = 100;

const int VALUE_MIN = -500;
const int VALUE_MAX = 500;

const char *PATH_DISK = "./disk.txt";
const char *PATH_TEMP = "./temp.txt";

int memory[SIZE_MEMORY];

void externalSort();
void merge(std::fstream &iosDisk, std::streamoff stPos, std::streamoff bndPos, std::streamoff enPos);
void genDisk();

int main()
{
    srand((unsigned)time(NULL));
    std::cout << "External Sort" << std::endl;
    std::cout << "Capacity (Disk / Memory) : " << SIZE_DISK << " / " << SIZE_MEMORY << std::endl;

    std::cout << "generate file filled with 500 random unsorted numbers" << std::endl;
    genDisk();

    std::cout << "sort" << std::endl;
    externalSort();
    std::cout << "done" << std::endl;

    // some test codes
    // ...

    return 0;
}

void genDisk()
{
    std::ofstream os(PATH_DISK, std::ios::trunc);

    for (int i = 0; i < SIZE_DISK; i++)
    {
        os << " " << rand() % (VALUE_MAX - VALUE_MIN) + VALUE_MIN;
    }
    os << std::endl;

    os.close();
}

// XXX
// IF SIZE_DISK % SIZE_MEMORY != 0 THEN
//     BREAKS
void externalSort()
{
    std::fstream ios(PATH_DISK, std::ios::in | std::ios::out);

    std::streamoff pos[SIZE_DISK / SIZE_MEMORY + 1];
    for (int i = 0; i < SIZE_DISK / SIZE_MEMORY; i++)
    {
        pos[i] = ios.tellg();
        for (int j = 0; j < SIZE_MEMORY; j++)
        {
            ios >> memory[j];
        }

        std::sort(memory, memory + SIZE_MEMORY);

        ios.seekp(pos[i]);
        for (int j = 0; j < SIZE_MEMORY; j++)
        {
            ios << " " << memory[j];
        }
        ios << std::flush;
    }
    pos[SIZE_DISK / SIZE_MEMORY] = ios.tellg();

    for (int i = 1; i < SIZE_DISK / SIZE_MEMORY; i++)
    {
        merge(ios, pos[0], pos[i], pos[i + 1]);
    }

    ios.close();
}

void merge(std::fstream &iosDisk, std::streamoff stPos, std::streamoff bndPos, std::streamoff enPos)
{
    std::streamoff lSidePos = stPos, rSidePos = bndPos;
    int lSideBiggest = VALUE_MIN - 1, rSideBiggest = VALUE_MIN - 1;

    iosDisk.seekg(lSidePos);
    for (int i = SIZE_MEMORY / 2; i < SIZE_MEMORY; i++)
    {
        iosDisk >> memory[i];
    }
    lSideBiggest = memory[SIZE_MEMORY - 1];
    lSidePos = iosDisk.tellg();

    std::fstream iosTemp(PATH_TEMP, std::ios::in | std::ios::out | std::ios::trunc);
    while (lSidePos != bndPos || rSidePos != enPos)
    {
        if (lSidePos == bndPos || lSideBiggest > rSideBiggest)
        {
            iosDisk.seekg(rSidePos);
            for (int i = 0; i < SIZE_MEMORY / 2; i++)
            {
                iosDisk >> memory[i];
            }
            rSideBiggest = memory[SIZE_MEMORY / 2 - 1];
            rSidePos = iosDisk.tellg();
        }
        else
        {
            iosDisk.seekg(lSidePos);
            for (int i = 0; i < SIZE_MEMORY / 2; i++)
            {
                iosDisk >> memory[i];
            }
            lSideBiggest = memory[SIZE_MEMORY / 2 - 1];
            lSidePos = iosDisk.tellg();
        }

        std::sort(memory, memory + SIZE_MEMORY);

        for (int i = 0; i < SIZE_MEMORY / 2; i++)
        {
            iosTemp << " " << memory[i];
        }
    }

    for (int i = SIZE_MEMORY / 2; i < SIZE_MEMORY; i++)
    {
        iosTemp << " " << memory[i];
    }

    iosTemp << std::flush;

    iosDisk.seekp(stPos);
    iosTemp.seekg(iosTemp.beg);
    while (!iosTemp.eof())
    {
        int temp;
        iosTemp >> temp;
        iosDisk << " " << temp;
    }
    iosDisk << std::flush;

    iosTemp.close();
}
