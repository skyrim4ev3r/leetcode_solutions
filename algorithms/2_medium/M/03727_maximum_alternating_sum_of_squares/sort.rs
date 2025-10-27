impl Solution {
    pub fn max_alternating_sum(mut nums: Vec<i32>) -> i64 {
        for mut num in nums.iter_mut() {
            *num *= *num;
        }

        nums.sort_unstable();

        let plus_index = nums.len() / 2;
        let mut res = 0_i64;

        nums[0..plus_index].iter().for_each(|&x| res -= x as i64);
        nums[plus_index..].iter().for_each(|&x| res += x as i64);

        res
    }
}
