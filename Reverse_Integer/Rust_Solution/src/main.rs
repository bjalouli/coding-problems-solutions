fn main() {
    let x = reverse(123);

    println!("Reversed number = {}" , x);
}


pub fn reverse(x: i32) -> i32 {
    let mut sum: i64 = 0 ;
    let mut y: i64 = x as i64 ;

    while y != 0 {
        sum = sum * 10 + y%10 ;
        y = y / 10 ; 
        if  sum  > 2147483647 || sum < -2147483648 {
            return 0 ;
        }
    }
    sum as i32
}
