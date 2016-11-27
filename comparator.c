#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comparator.h"

int cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;

    return strcmp(*ia, *ib);
}

