impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0_usize;
        let mut right = height.len() - 1;
        let mut max_water = 0_i32;

        while left < right {
            let hl = height[left];
            let hr = height[right];
            let min_height = hl.min(hr);
            let curr_water = (right - left) as i32 * min_height;
            max_water = max_water.max(curr_water);

            if hl < hr {
                left += 1;
            } else {
                right -= 1;
            }
        }

        max_water
    }
}
