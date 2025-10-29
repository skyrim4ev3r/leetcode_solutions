impl Solution {
    pub fn maximum_gap(mut nums: Vec<i32>) -> i32 {

        let mut counts = [0_usize; 10];
        let mut pos = 1_i32;
        let len = nums.len();
        let mut sorted_vec = vec![0_i32; len];

        let mut shift = i32::MAX;
        for i in 0..len {
           shift = shift.min(nums[i]);
        }

        let mut max_num = i32::MIN;
        for i in 0..len {
            nums[i] -= shift;
            max_num = max_num.max(nums[i]);
        }

        while pos <= max_num {
            for i in 0..10 {
                counts[i] = 0;
            }

            for i in 0..len {
                let counts_index = ((nums[i] / pos) % 10) as usize;
                counts[counts_index] += 1;
            }

            let mut start_index = 0_usize;
            for i in 0..10 {
                let count = counts[i];
                counts[i] = start_index;
                start_index += count;
            }

            for i in 0..len {
                let counts_index = ((nums[i] / pos) % 10) as usize;
                sorted_vec[counts[counts_index]] = nums[i];
                counts[counts_index] += 1;
            }
            std::mem::swap(&mut sorted_vec, &mut nums);
            pos *= 10;
        }

        /*

        for i in 0..len {
            nums[i] += shift;
        }

        */

        let mut max = 0_i32;
        for i in 1..len {
            max = max.max(nums[i] - nums[i - 1]);
        }

        max
    }
}
