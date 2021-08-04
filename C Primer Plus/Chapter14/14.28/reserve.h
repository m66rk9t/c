#include <stdbool.h>

struct seat{
    char num[3];
    bool reserved;
    char fname[21];
    char lname[21];
}; //结构声明，座位信息

struct seat F102[12] =
{
    {"1A", false},{"1B", false},{"1C", false},
    {"2A", false},{"2B", false},{"2C", false},
    {"3A", false},{"3B", false},{"3C", false},
    {"4A", false},{"4B", false},{"4C", false}
};

struct seat F311[12] =
{
    {"1A", false},{"1B", false},{"1C", false},
    {"2A", false},{"2B", false},{"2C", false},
    {"3A", false},{"3B", false},{"3C", false},
    {"4A", false},{"4B", false},{"4C", false}
};

struct seat F444[12] =
{
    {"1A", false},{"1B", false},{"1C", false},
    {"2A", false},{"2B", false},{"2C", false},
    {"3A", false},{"3B", false},{"3C", false},
    {"4A", false},{"4B", false},{"4C", false}
};

struct seat F519[12] =
{
    {"1A", false},{"1B", false},{"1C", false},
    {"2A", false},{"2B", false},{"2C", false},
    {"3A", false},{"3B", false},{"3C", false},
    {"4A", false},{"4B", false},{"4C", false}
};