impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        const MAX_NUM: usize = 100;
        let mut freqs = [0; MAX_NUM];

        nums.into_iter().for_each(|num| freqs[num as usize] += 1);
        
        let mut res: Vec<i32> = Vec::new();
        for i in 0..MAX_NUM {
            if freqs[i] > 1 {
                res.push(i as i32);
            }
        }

        res
    }
}
