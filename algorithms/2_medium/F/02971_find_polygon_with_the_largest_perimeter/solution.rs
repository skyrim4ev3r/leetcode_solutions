impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i64 {
        nums.sort_unstable();
        let mut sum = nums.iter().map(|x| *x as i64).sum::<i64>();

        for i in (2..nums.len()).rev() {
            let largest_side = nums[i] as i64;

            if largest_side * 2 < sum {
                return sum;
            }

            sum -= largest_side;
        }

        -1
    }
}
