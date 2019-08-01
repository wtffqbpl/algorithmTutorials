#include <stdio.h>
#define MAX_VALUE (0xFFFFFFF)

int coinChange(int const *coinList, const int coinCataNum, const int changes)
{
    // Abnormal cases.
    if (changes < 0) {
        return -1;
    }
    // 0 ... n: [n+1]
    int f[changes+1];
    int idx, jdx;

    f[0] = 0;
    for (idx = 1; idx <= changes; idx++) {
        f[idx] = MAX_VALUE;
        for (jdx = 0; jdx < coinCataNum; jdx++) {
            if ((idx >= coinList[jdx]) && (f[idx-coinList[jdx]] != MAX_VALUE)) {
                f[idx] = (f[idx-coinList[jdx]]+1) > f[idx] ? f[idx] : (f[idx-coinList[jdx]]+1);
            }
        }
    }

    if (MAX_VALUE == f[changes]) {
        f[changes] = -1;
    }

    return f[changes];
}

int main()
{
    int coinList[] = {2, 5, 7};
    int coinCataNum = 3;
    int expectedChanges = 27;
    int minCoinNum = 0;

    minCoinNum = coinChange(coinList, coinCataNum, expectedChanges);

    printf("Min Coin Num is: %d\n", minCoinNum);

    return 0;
}