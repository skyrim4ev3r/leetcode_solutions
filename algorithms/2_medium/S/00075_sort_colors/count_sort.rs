impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        const COLOR_COUNT: usize = 3;
        let mut freqs = [0_i32; COLOR_COUNT];

        for &num in nums.iter() {
            freqs[num as usize] += 1;
        }

        let mut nums_index = 0_usize;
        for (i, freq) in freqs.into_iter().enumerate() {
            let color = i as i32;
            for _ in 0..freq {
                nums[nums_index] = color;
                nums_index += 1;
            }
        }
    }
}
