#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int* results = (int *)malloc(sizeof(int) * 2);

    for (size_t i = 0; i < numsSize-1; i++) {
        for (size_t j = i+1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                results[0] = i;
                results[1] = j;
                goto end_flag;
            }
        }
    }

end_flag:

    returnSize = results;
    return results;
}

int main()
{
    int returnSize;
    int nums[] = {2, 7, 11, 5};

    int* results;

    results = twoSum(nums, 4, 9, &returnSize);

    printf("%d  %d\n", results[0], results[1]);

    free(results);

    return 0;

}
