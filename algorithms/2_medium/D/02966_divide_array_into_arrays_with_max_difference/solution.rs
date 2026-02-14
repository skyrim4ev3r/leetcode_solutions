impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let len = nums.len();

        if len < 3 || len % 3 != 0 {
            return Vec::new();
        }

        nums.sort_unstable();

        for i in (0..len).step_by(3) {
            if nums[i + 2] - nums[i] > k {
                return Vec::new();
            }
        }

        let mut res: Vec<Vec<i32>> = Vec::with_capacity(len / 3);

        for i in (0..len).step_by(3) {
            res.push(nums[i..(i + 3)].to_vec());
        }

        res
    }
}
