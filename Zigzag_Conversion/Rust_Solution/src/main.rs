use core::num;

fn main() {
    let str = convert(String::from("ABCD"), 2) ;

    println!("string = {}" , str);
}


pub fn convert(s: String, num_rows: i32) -> String {
    if num_rows == 1 || num_rows == s.len()as i32 {
        return  s;
    }

    let mut row: i32 = 0;
    let mut down = 1;
    let mut tab =  vec![String::new() ; num_rows as usize] ;

    for ch in s.chars() {
        tab[row as usize].push(ch);

        if row == 0 {
            down = 1 ;
        }else if row == num_rows - 1 {
            down = -1;
        }

        row += down ;

    }

    tab.concat()
    
}