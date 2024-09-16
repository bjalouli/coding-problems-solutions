#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;  
    }

    int len = strlen(s);
    int goDown = 1 ;
    int currRow = 0 ;
    char* rows[numRows];

    for (int i = 0 ; i < numRows ; i++) {
        rows[i] = (char*)malloc(len * sizeof(char));
        rows[i][0] = '\0';
    }

    for (int i = 0 ; i < len ; i++) {
        strncat(rows[currRow] , &s[i] , 1);
        if ( currRow == 0 ) {
            goDown = 1;
        } else if (currRow == numRows -1 ){
            goDown = -1;
        }
        currRow += goDown ;
    }

    char* result = (char*)malloc(len+1 * sizeof(char));
    result[0]='\0';

    
    for (int i = 0; i < numRows; i++)
    {
        strcat(result , rows[i]);
        free(rows[i]);
    }

     result[len+1] = '\0';
    return result;
}

int main() {
    char* s = "ABCD";
    int numRows = 2;
    char* str = convert(s, numRows);
    printf("Final string: %s\n", str);

    free(str);  // Free dynamically allocated memory
    return 0;
}
