//if all numbers be equal then 0 bitwise op needed, else 1 bitwise op with range of L=0 to R=nums.size()-1
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        nums.iter().any(|&c| c != nums[0]) as i32
    }
}
