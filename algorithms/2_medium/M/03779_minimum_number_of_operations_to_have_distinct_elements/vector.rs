impl Solution {
    fn normalize_the_vec(nums: &mut Vec<i32>) {
        let min_elem = nums.iter().map(|x| *x).min().unwrap(); 

        for num in nums.iter_mut() {
            *num -= min_elem;
        }
    }

    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();
        Self::normalize_the_vec(&mut nums);
        let max_elem = nums.iter().map(|x| *x).max().unwrap();
        let mut seen = vec![false; max_elem as usize + 1];

        for i in (0..len).rev() {
            let cache = &mut seen[nums[i] as usize];
            if *cache {
                return ((i / 3) + 1) as i32;
            }
            *cache = true;
        }

        0
    }
}
