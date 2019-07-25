#include <stdio.h>
#include <string.h>


char * reverseWords(char * s){
    int startIdx = 0;
    int endIdx = 0;
    int loopIdx;
    char charTmp;

    for (size_t loopIdx = 0; loopIdx <= strlen(s); loopIdx++) {
        if ((' ' == s[loopIdx]) || ('\0' == s[loopIdx])) {
            endIdx = loopIdx;
            for (size_t innerLoopIdx = 0; innerLoopIdx < (endIdx - startIdx)/2; innerLoopIdx++) {
                charTmp = s[innerLoopIdx+startIdx];
                s[innerLoopIdx+startIdx] = s[endIdx-1-innerLoopIdx];
                s[endIdx-1-innerLoopIdx] = charTmp;
            }
            startIdx = endIdx+1;
        }
    }

    return s;
}

int main()
{
    char s[] = "Let's take LeetCode contest";

    printf("%s\n", reverseWords(s));

    return 0;
}
