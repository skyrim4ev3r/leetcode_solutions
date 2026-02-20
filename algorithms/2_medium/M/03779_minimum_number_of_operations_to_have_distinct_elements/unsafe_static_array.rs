impl Solution {
    const MAX_INPUT: usize = 100_000;

    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();
        static mut SEEN: [bool; Solution::MAX_INPUT + 1] = [false; Solution::MAX_INPUT + 1];
        let max_elem = nums.iter().map(|x| *x).max().unwrap();

        unsafe {
            for i in 0..=(max_elem as usize) {
                SEEN[i] = false;
            }

            for i in (0..len).rev() {
                let cache = &mut SEEN[nums[i] as usize];
                if *cache {
                    return ((i / 3) + 1) as i32;
                }
                *cache = true;
            }
        }   

        0
    }
}
