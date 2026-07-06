#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int n = strlen(s);

    int countStack[100];
    char* stringStack[100];
    int top = -1;

    char* curr = (char*)malloc(100005);
    curr[0] = '\0';

    int k = 0;

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        }

        else if (s[i] == '[') {
            countStack[++top] = k;

            stringStack[top] = (char*)malloc(strlen(curr) + 1);
            strcpy(stringStack[top], curr);

            curr[0] = '\0';
            k = 0;
        }

        else if (s[i] == ']') {
            int repeat = countStack[top];

            char* prev = stringStack[top--];

            char* temp = (char*)malloc(100005);
            strcpy(temp, prev);

            for (int j = 0; j < repeat; j++)
                strcat(temp, curr);

            strcpy(curr, temp);

            free(prev);
            free(temp);
        }

        else {
            int len = strlen(curr);
            curr[len] = s[i];
            curr[len + 1] = '\0';
        }
    }

    return curr;
}