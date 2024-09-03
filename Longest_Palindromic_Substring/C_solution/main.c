#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return "";
    }

    int longest_palindrome_length = 0;
    int start_index = 0;
    int end_index = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (is_palindrome(s, i, j)) {
                int current_palindrome_length = j - i + 1;
                if (current_palindrome_length > longest_palindrome_length) {
                    longest_palindrome_length = current_palindrome_length;
                    start_index = i;
                    end_index = j;
                }
            }
        }
    }

    char* result = (char*)malloc((longest_palindrome_length + 1) * sizeof(char));
    strncpy(result, s + start_index, longest_palindrome_length);
    result[longest_palindrome_length] = '\0';  

    return result;
}


int main() {

    char* str = "cbbd";
    printf("result = %s \n" , longestPalindrome(str));
    return 0;
}
