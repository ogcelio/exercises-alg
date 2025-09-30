#include "2-2.h"
#include <climits>

void min_max(int *array, int size, int &min, int &max)
{
    min = INT_MAX;
    max = INT_MIN;
    for (int i = 0; i < size; i++){
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
}
