impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {

        // Its more efficent to use fixed size array here because:
        // 1 <= nums[i] <= 100
        let mut freqs = [0_i32; 101];
    
        for num in nums.into_iter() {
            freqs[num as usize] += 1;
        }

        let mut count = 0;
        for freq in freqs.into_iter() {
            // A pair (i, j) is called good if nums[i] == nums[j] and i < j.
            // So if there be five ones like: 1,1,1,1,1
            // For lowest index of nums[i] = 1 there is 4 good pair, next i have 3 good pairs, next 2, next 1
            // 1 + 2 +...+ n = (n * (n + 1)) /2
            // n = freq - 1 =>  n + 1 = freq  => ((freq - 1) * freq) / 2
            count += ((freq - 1) * freq) / 2;
        }

        count
    }
}
