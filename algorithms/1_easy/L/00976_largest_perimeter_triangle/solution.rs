impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {        
        nums.sort_unstable_by(|a, b| b.cmp(a));

         if let Some(arr) = nums.windows(3).find(|&arr| arr[0] < arr[1] + arr[2]) {
            arr.iter().sum()
        } else {
            0
        }
    }
}
