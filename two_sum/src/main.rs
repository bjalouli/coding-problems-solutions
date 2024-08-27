use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;

            if let Some(&index) = map.get(&complement) {
                return vec![index as i32, i as i32];
            }

            map.insert(num, i);
        }

        unreachable!()
    }
}

fn main() {
    let nums = vec![1,2,3,4,5,6,7,8,9,10];
    let target = 10;

    let result = Solution::two_sum(nums.clone(), target);

    println!("Indices: {:?}", result);
}