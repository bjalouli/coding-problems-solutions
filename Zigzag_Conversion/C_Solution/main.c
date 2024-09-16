#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* convert(char* s, int numRows) {
    if (numRows == 1){
        return s;
    }
    char tab[1000][100] = {0};
    int r = 0 ;
    int c = 0;
    int down = 1;
    for (int i = 0; i < strlen(s); i++) {
        tab[r][c] = s[i];  
        
        if (down){
            r++;
            if ( r == numRows) {
                r -= 2;
                c++;
                down = 0;
            }
        }else{
            r--;
            c++;
            if ( r < 0){
                r = 1 ;
                c--;
                down = 1 ;
            }

        }
    }
    
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char)); 
    int index = 0;

    for (int i = 0 ; i < numRows ; i ++) {
        for (int j = 0 ; j<= c ; j ++) {
            if (tab[i][j] !=0){
                result[index++] = tab[i][j];
            }
        }
    }
    result[index] = '\0';
    printf("Zigzag string: %s\n", result);
    return result;
}

int main() {
    char * s = "PAYPALISHIRING";
    char *str = convert(s , 3);
    printf("string = %s \n" , str);
    return 0;
}

