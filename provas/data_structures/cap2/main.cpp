#include "2-2.h"
#include <iostream>

int
main()
{
    int array[7] = {1, 2, 3, 4, 10, 20, -1};
    int min, max;

    min_max(array, 7, min, max);

    std::cout << "Min: " << min << ", Max: " << max << std::endl;

    return 0;
}
