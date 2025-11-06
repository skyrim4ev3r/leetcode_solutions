impl Solution {
    fn is_prime(num: i32) -> bool {
         if num == 2 {
            return true;
        }

        if num <= 1 || num % 2 == 0 {
            return false;
        }

        let sq = (num as f64).sqrt() as i32;
        for i in (3..=sq).step_by(2) {
            if num % i == 0 {
                return false;
            }
        }

        true
    }

    pub fn diagonal_prime(nums: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut max = 0_i32;

        for i in 0..n {

            if max < nums[i][i] && Self::is_prime(nums[i][i]) {
                max = nums[i][i];
            }

            if max < nums[i][n - 1 - i] && Self::is_prime(nums[i][n - 1 - i]) {
                max = nums[i][n - 1 - i];
            }
        }

        max
    }
}
