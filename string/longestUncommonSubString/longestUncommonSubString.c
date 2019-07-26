#include <stdio.h>
#include <string.h>

int findLULength(char* a, char* b)
{
    return (strcmp(a, b) ? (strlen(a) > strlen(b) ? strlen(a) : strlen(b)) : -1);
}

int main()
{
    char a[] = "aab";
    char b[] = "ddd";

    printf("The Longest uncommon sub string: %d\n", findLULength(a, b));
    printf("%d\n", strcmp(a, b));
    return 0;
}
