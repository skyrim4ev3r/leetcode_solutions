impl Solution {
    pub fn get_xor_sum(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {
        arr1.iter().fold(0_i32, |res, &x| res ^ x) & arr2.iter().fold(0_i32, |res, &x| res ^ x)
    }
}
