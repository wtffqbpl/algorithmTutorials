#include <stdio.h>

#define FALSE (0)
#define TRUE  (1)

enum JUMPSTATUS {
    CANNOT_JUMP = 0,
    CAN_JUMP,

    STATUS_BUTT
};

int canJumpToSpecifiedStation()
{
    return FALSE;
}

int main()
{
    char* jump_status[STATUS_BUTT] = {"FALSE", "TRUE"};
    int jump_results = 0;

    jump_results = canJumpToSpecifiedStation();

    printf("Can frog jump to specified stone? %s\n", jump_status[jump_results]);

    return 0;
}