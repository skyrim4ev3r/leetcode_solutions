impl Solution {
    #[inline]
    fn is_odd(num: &i32) -> bool {
        (*num & 1) == 1
    }

    #[inline]
    fn is_even(num: &i32) -> bool {
        (*num & 1) == 0
    }

    pub fn sort_array_by_parity(mut nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut even_index = 0_usize;
        let mut odd_index = len - 1;

        loop {
            while even_index < len && Self::is_even(&nums[even_index]) {
                even_index += 1;
            }

            while odd_index < len && Self::is_odd(&nums[odd_index]) {
                odd_index -= 1;
            }

            if even_index >= len || odd_index >= len || even_index >= odd_index {
                break;
            }

            let tmp = nums[even_index];
            nums[even_index] = nums[odd_index];
            nums[odd_index] = tmp;

            odd_index -= 1;
            even_index += 1;
        }

        nums
    }
}
