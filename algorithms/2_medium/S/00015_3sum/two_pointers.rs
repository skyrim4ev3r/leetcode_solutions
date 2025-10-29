impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {

        nums.sort_unstable();

        let len = nums.len();
        let mut res: Vec<Vec<i32>> = Vec::new();

        if nums[len - 1] < 0 {
            return res;
        }

        for left in 0..(len - 2) {
            if nums[left] > 0 {
                break;
            }

            if left > 0 && (nums[left] == nums[left - 1] || nums[left].abs() > nums[len - 1] * 2) {
                continue;
            }

            let mut right = len - 1;
            let mut mid = left + 1;

            while mid < right {
                let sum = nums[left] + nums[mid] + nums[right];

                if sum < 0 {
                    mid += 1;
                } else if sum > 0 {
                    right -= 1;
                } else {
                    res.push(vec![nums[left],nums[mid],nums[right]]);

                    loop {
                        mid += 1;

                        if mid >= right || nums[mid] != nums[mid - 1] {
                            break;
                        }
                    }
                }
            }
        }

        res
    }
}
