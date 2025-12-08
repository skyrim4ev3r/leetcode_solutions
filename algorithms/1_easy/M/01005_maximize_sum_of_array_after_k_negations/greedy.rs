impl Solution {
    pub fn largest_sum_after_k_negations(mut nums: Vec<i32>, mut k: i32) -> i32 {
        nums.sort_unstable();

        let len = nums.len();
        let mut curr_index = 0_usize;

        while curr_index < len && nums[curr_index] < 0 && k > 0 {
            nums[curr_index] *= -1;
            k -= 1;
            curr_index += 1;
        }

        let sum = nums.iter().map(|num| *num).sum::<i32>();

        if k % 2 == 0 {
            return sum;
        }

        sum - 2 * (*nums.iter().min().unwrap())
    }
}
