use std::collections::HashMap;

struct Solution;

impl Solution {
    #[cfg(feature = "hashmap")]
    // Optimized Approach (O(n))
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

    #[cfg(feature = "loop")]
    // Brure-force approach O(n²)) 
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() {
            for j in i + 1..nums.len() {
                if nums[i] + nums[j] == target {
                    return vec![i as i32, j as i32];
                }
            }
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