#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int myAtoi(char* s) {
    
    long result = 0;
    int i = 0 ;
    char sig = 1;
    while(isspace(s[i])){
        i++;
    }

    if ( s[i] == '+') {
        sig = 1;
        i++;
    }else if (s[i] == '-') {
        sig = -1;
        i++;
    }

    while (isdigit(s[i]))
    {
        result = result * 10 + ((int)s[i] - 48 );
        if (result *sig > 2147483647) {
            result = 2147483647 ;
            return result;
        }else if ( result *sig < -2147483648) {
            result = -2147483648;
            return result;
        }
        i++;
    }

    result *= sig;

    printf("result = %ld \n" , result);
    

    printf("result = %ld \n" , result);
    
    

    return (int) result;
}


int main() {
    char* str = "20000000000000000000" ;

    int x =  myAtoi(str);
    printf("result = %d \n" , x);

    return 0;
}