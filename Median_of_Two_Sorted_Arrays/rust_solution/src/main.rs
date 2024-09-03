
pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
    let l1 = nums1.len();
    let l2 = nums2.len();
    let mut l3 = Vec::new();
    let mut med: f64= 0.0 ;
    for ( i , k) in nums1.iter().enumerate() {
        l3.push(*k);
    }

    for ( i , k) in nums2.iter().enumerate() {
        l3.push(*k);
    }
    l3.sort();

    let x = (l1 + l2 ) /2 ;
    if x%2 == 0 {
        med = ((l3[x] + l3[x-1] )as f64)/2.0  ;
    }else {
        med = (l3[x]).into() ;
    }
    
    med 
}


fn main() {
    let nums1 = vec![1,2]; 
    let nums2 = vec![3,4];

    let x = find_median_sorted_arrays(nums1, nums2);
    println!("medium = {}" , x);
}
