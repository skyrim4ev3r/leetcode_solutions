impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort_unstable();

        let mut res = nums[0] + nums[1] + nums[2];
        let len = nums.len();

        for i in 0..len {
            let mut left = i + 1;
            let mut right = len - 1;

            while left < right {
                let temp = nums[i] + nums[left] + nums[right];

                if (res - target).abs() > (temp - target).abs() {
                    res = temp;
                }

                if temp < target {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }

        res
    }
}
