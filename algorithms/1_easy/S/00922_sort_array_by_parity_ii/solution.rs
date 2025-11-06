impl Solution {
    pub fn sort_array_by_parity_ii(mut nums: Vec<i32>) -> Vec<i32> {
        let mut odd_index = 1_usize;
        let mut even_index = 0_usize;
        let len = nums.len();

        while odd_index < len && even_index < len {
            while odd_index < len && (nums[odd_index] & 1) == 1 {
                odd_index += 2;
            }
            while even_index < len && (nums[even_index] & 1) == 0 {
                even_index += 2;
            }

            if odd_index >= len && even_index >= len {
                break;
            }

            let tmp = nums[even_index];
            nums[even_index] = nums[odd_index];
            nums[odd_index] = tmp;

            odd_index += 2;
            even_index += 2;
        }

        nums
    }
}
