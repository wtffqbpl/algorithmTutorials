#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  0
#define FALSE 1

int numUniqueEmails(char ** emails, int emailsSize){

    int findPlusFlag = FALSE;
    int findAtFlag = FALSE;
    char* email;
    size_t mailLength = 0;
    char charTmp;
    size_t newmailIdx;
    int hasBeenHave = FALSE;
    int newMailsIdx = 0;
    char** newEmails = (char **)malloc(emailsSize * sizeof(char*));

    for (size_t emailIdx = 0; emailIdx < emailsSize; emailIdx++) {
        email = emails[emailIdx];
        mailLength = strlen(email);

        char* newMail = (char *)malloc(sizeof(char) * (mailLength+1));

        newmailIdx = 0;
        findAtFlag = FALSE;
        findPlusFlag = FALSE;
        for (size_t idx = 0; idx < mailLength; idx++) {
            charTmp = email[idx];
            if ('@' == charTmp) findAtFlag = TRUE;
            if ('+' == charTmp) findPlusFlag = TRUE;
            if ((FALSE == findPlusFlag) && (FALSE == findAtFlag) && ('.' != charTmp)) {
                newMail[newmailIdx] = charTmp;
                newmailIdx++;
            } else if (TRUE == findAtFlag) {
                newMail[newmailIdx] = charTmp;
                newmailIdx++;
            }
        }
        newMail[newmailIdx] = '\0';
        newEmails[emailIdx] = newMail;
        printf("%s\n", newEmails[emailIdx]);

        hasBeenHave = FALSE;
        for (size_t idx = 0; idx < newMailsIdx; idx++) {
            if (strcmp(newEmails[idx], newMail)) {
                hasBeenHave = TRUE;
                printf("Hello world\n");
                break;
            }
        }
        if (TRUE != hasBeenHave) {
            newEmails[newMailsIdx] = newMail;
            printf("%s\n", newEmails[newMailsIdx]);
            newMailsIdx++;
        }
    }

    return newMailsIdx+1;
}


int main()
{
    char* emails[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    printf("%s\n", emails[0]);
    printf("%s\n", emails[1]);
    printf("%s\n", emails[2]);

    numUniqueEmails(emails, 3);
    return 0;
}
