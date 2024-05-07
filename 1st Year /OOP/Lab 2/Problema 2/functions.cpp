#include "functions.h"
#include <cstring>
#include <cstdio>

int compName(header s1, header s2)
{
    int result = strcmp(s1.getNume(), s2.getNume());
    if (result == 0) {
        return 0;
    } else if (result > 0) {
        return 1;
    } else {
        return -1;
    }
}

int compAvg(header s1, header s2)
{
    if (s1.getAverage() == s2.getAverage())
        return 0;
    else if (s1.getAverage() > s2.getAverage())
        return 1;
    else return -1;
}

int compEng(header s1, header s2)
{
    if (s1.getEng() == s2.getEng())
        return 0;
    else if (s1.getEng() > s2.getEng())
        return 1;
    else return -1;
}

int compIst(header s1, header s2)
{
    if (s1.getIst() == s2.getIst())
        return 0;
    else if (s1.getIst() > s2.getIst())
        return 1;
    else return -1;
}

int compMate(header s1, header s2)
{
    if (s1.getMate() == s2.getMate())
        return 0;
    else if (s1.getMate() > s2.getMate())
        return 1;
    else return -1;
}
