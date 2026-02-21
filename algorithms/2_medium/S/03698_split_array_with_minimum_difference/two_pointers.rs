impl Solution {
    pub fn split_array(nums: Vec<i32>) -> i64 {
        let len = nums.len();

        let mut left = 0_usize;
        while left + 1 < len && nums[left] < nums[left + 1] {
            left += 1;
        }

        let mut right = len - 1;
        while right > 0 && nums[right - 1] > nums[right] {
            right -= 1;
        }

        if left == right {
            let index = left;
            let sum_left_part = nums[0..index].iter().map(|x| *x as i64).sum::<i64>();
            let sum_right_part = nums[(index + 1)..].iter().map(|x| *x as i64).sum::<i64>();

            if index == len - 1 {
                return (sum_left_part - nums[index] as i64).abs();
            } else if index == 0 {
                return (nums[index] as i64 - sum_right_part).abs();
            } else {
                let max = sum_left_part.max(sum_right_part);
                let min = sum_left_part.min(sum_right_part);

                return (max - (min + nums[index] as i64)).abs();
            }
        } else if left + 1 == right {
            let sum_left_part = nums[0..=left].iter().map(|x| *x as i64).sum::<i64>();
            let sum_right_part = nums[right..].iter().map(|x| *x as i64).sum::<i64>();

            return (sum_left_part - sum_right_part).abs();
        } else {
            return -1;
        }
    }
}
