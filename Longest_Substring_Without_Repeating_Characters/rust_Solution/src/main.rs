use std::collections::HashMap;

fn length_of_longest_substring(s: &str) -> i32 {
    let mut last_seen = HashMap::new();
    let mut start = 0;
    let mut max_len = 0;

    for (i, c) in s.chars().enumerate() {
        if let Some(&last_index) = last_seen.get(&c) {
            if last_index >= start {
                start = last_index + 1;
            }
        }

        last_seen.insert(c, i);
        max_len = max_len.max(i - start + 1);
    }

    max_len
}

fn main() {
    let str = "abcabcbb";
    let len = length_of_longest_substring(str);
    println!("Length of the longest substring without repeating characters = {}", len);
}