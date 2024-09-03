#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char* s) {

    int len = strlen(s);

    if ( len == 0 ) {
        return -1;
    }

    if ( len == 1 ) {
        return 1;
    }


    
    int tab_of_chars[255] = {-1};
    int x = 0 , y = 0 ;
    
    int sub_len = 0 ;

    while (x < len) {

        while (tab_of_chars[s[x]] == 1 )
        {
            tab_of_chars[s[y]] = -1 ;
            y++;
        }
        
        tab_of_chars[s[x]] = 1;
        if (sub_len < x - y + 1 ) {
            sub_len = x - y + 1 ;
            printf("len = %d" , sub_len);
        }

        x++;

    }

    return sub_len;
}

int main() {
    char* str = "cbbn";
    int len = lengthOfLongestSubstring(str);
    printf("length of the substring = %d \n" , len);
}