use std::i32::MAX;
use std::thread::sleep;
use std::time::Duration;

fn main() {
    let x = my_atoi("   -123".to_string());
    

}

pub fn my_atoi(s: String) -> i32 {
    let mut result: i64 = 0;
    let mut flag = false ;
    let mut sig = 1 ;
    let mut it = s.chars().peekable();
    while !flag {
        if let Some(space ) = it.peek() {
            if space.is_whitespace() {
                println!("space");
                it.next();
            }else {
                flag = true;
            }
        } else {
            flag = true ;
        }
    }
    
    if let Some(sigi) = it.peek() {
        if sigi == &'-' {
            sig *= -1;
            it.next();
        } else if sigi == &'+' {
            sig *= 1;
            it.next();
        }
    }

    while flag {
        if let Some(num) = it.peek() {
            if num.is_digit(10) {
                result = result * 10 + num.to_digit(10).unwrap()as i64;

                if result *sig > i32::MAX as i64{
                    result = 2147483647 ;
                    return result as i32;
                }else if  result *sig < -2147483648 as i64   {
                    result = -2147483648;
                    return result as i32;
                }
                it.next();
            }else {
                flag = false;
            }
        }else {
            flag = false;
        }
    }


    (result * sig ) as i32
}
