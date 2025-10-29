impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {

        const colors_len: usize = 3;
        let mut colors_count = [0_i32; colors_len];

        for &num in nums.iter() {
            colors_count[num as usize] += 1;
        }

        let mut nums_index = 0_usize;
        for i in 0..colors_len {
            let i_32 = i as i32;
            for _ in 0..colors_count[i] {
                nums[nums_index] = i_32;
                nums_index += 1;
            }
        }
    }
}
