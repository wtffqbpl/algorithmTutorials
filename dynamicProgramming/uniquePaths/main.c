#include <stdio.h>

/*
    LintCode 114: Unique Paths.
 */

int countUniquePaths(const int m, const int n)
{
    // Abnormal cases.
    if ((m <= 0) || (n <= 0)) return 0;

    // status
    int status_func[m][n];

    for (int idx = 0; idx < m; idx++) {     // up to down
        for (int jdx = 0; jdx < n; jdx++) { // left to right
            if ((idx == 0) || (jdx == 0)) {
                status_func[idx][jdx] = 1;
            } else {
                status_func[idx][jdx] = status_func[idx-1][jdx] + status_func[idx][jdx-1];
            }
        }
    }

    return status_func[m-1][n-1];
}


int main()
{
    int m = 10;
    int n = 20;
    int uniquePaths = 0;

    uniquePaths = countUniquePaths(m, n);
    printf("The max unique Paths is: %d.\n", uniquePaths);

    return 0;
}