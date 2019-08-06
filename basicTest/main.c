#include <stdio.h>

int array[] = {23, 24, 12, 32, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))

int main(int argc, char** argv)
{
    int d = -1, x;

    printf("The first results of (%d <= (%d - 2)): ", d, TOTAL_ELEMENTS);
    if (d <= TOTAL_ELEMENTS - 2) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    /* TODO explanation. */

    printf("The second results of (%d <= (%d - 2)): ", d, TOTAL_ELEMENTS);
    if (d <= (int)TOTAL_ELEMENTS - 2) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    return 0;
}
