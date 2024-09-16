#include <stdio.h>
#include <math.h>



int reverse(int x){

    long sum = 0 ;
    while( x != 0 ) {
        sum = sum * 10 + x % 10 ;
        x = x / 10 ;
        if ( sum > 2147483647 || sum < -2147483648 ) {
            return 0 ;
        }
        printf("sum = %ld \n" , sum );
    }
    
    return  (int )sum;
}

int main() {
    int x = 1534236469;
    printf("reverse number of %d = %d \n" , x, reverse(x));
    return 0;
}


