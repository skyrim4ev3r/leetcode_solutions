impl Solution {
    pub fn first_unique_freq(nums: Vec<i32>) -> i32 {
        let max_num = *nums.iter().max().unwrap();
        let mut freqs = vec![0_i32; max_num as usize + 1];

        for &num in nums.iter() {
            freqs[num as usize] += 1;
        }

        let max_freq = *freqs.iter().max().unwrap();
        let mut freqs_of_freqs = vec![0_i32; max_freq as usize + 1];

        for &freq in freqs.iter() {
            freqs_of_freqs[freq as usize] += 1;
        }

        for &num in nums.iter() {
            let freq = freqs[num as usize];

            if freqs_of_freqs[freq as usize] == 1 {
                return num;
            }
        }

        -1
    }
}
