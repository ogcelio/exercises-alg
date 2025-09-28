#include <iostream>
#include "bucket_sort.h"
using namespace std;

int
main()
{
    unsigned int i;

    int list[] = {10, 9, 1, 4, 4, 3, 2};
    int size = 7;

    for (i = 0; i < size; i++)
    {
        cout << list[i] << endl;
    }

    cout << '\n' << endl;

    bucket_sort(list, size);

    for (i = 0; i < size; i++)
    {
        cout << list[i] << endl;
    }

    return 0;
}
