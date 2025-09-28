#include <cstdlib>

void
insertion_sort(int *list, int size)
{
    unsigned int i, j;

    int temp;

    for (i = 1; i < size; i++)
    {
        j = i;
        while (j > 0 && list[j] < list[j-1])
        {
            temp = list[j-1];
            list[j-1] = list[j];
            list[j] = temp;
            j--;
        }
    }
}
