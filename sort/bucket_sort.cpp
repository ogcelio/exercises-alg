#include "bucket_sort.h"
#include <algorithm>
using namespace std;

void
bucket_sort(int *list, int size)
{
    if (size <= 0) return; // checking if the array is empty

    unsigned int i, j;
    unsigned int k = 0;

    long int m = *max_element(list, list + size); // collecting the max element

    int *aux = (int *) malloc((m + 1) * 4);

    for (i = 0; i <= m; i++) // building the auxiliar array
    {
        aux[i] = 0;
    }

    for (i = 0; i < size; i++) // completing the auxiliar array
    {
        aux[list[i]]++;
    }

    for (i = 0; i <= m; i++) // sorting the array
    {
        for (j = 0; j < aux[i]; j++)
        {
            list[k] = i;
            k++;
        }
    }

    delete[] aux;
}
