impl Solution {
    const MOD_TO: i64 = 1_000_000_007;

    pub fn sum_distance(nums: Vec<i32>, s: String, d: i32) -> i32 {
        let len = nums.len();
        let bytes = s.as_bytes();
        let d = d as i64;
        let mut nums = nums.into_iter().map(|x| x as i64).collect::<Vec<i64>>();

        for i in 0..len {
            if bytes[i] == b'R' {
                nums[i] += d;
            } else {
                nums[i] -= d;
            }
        }

        nums.sort_unstable();

        let mut res = 0_i64;
        let mut prefix = 0_i64;

        for i in 1..len {
            prefix += (i as i64) * (nums[i] - nums[i - 1]).abs();
            res = (res + prefix) % Self::MOD_TO;
        }

        res as i32
    }
}
