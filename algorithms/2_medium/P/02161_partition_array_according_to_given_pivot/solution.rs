impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let len = nums.len();
        debug_assert!(len > 0);
        let mut res = vec![0_i32; len];
        let mut lo = 0_isize;
        let mut hi = len as isize - 1;

        for num in nums {
            match num.cmp(&pivot) {
                std::cmp::Ordering::Less => {
                    res[lo as usize] = num;
                    lo += 1;
                },
                std::cmp::Ordering::Greater => {
                    res[hi as usize] = num;
                    hi -= 1;
                },
                _ => {},
            }
        }

        res[((hi + 1) as usize)..len].reverse();

        for i in lo..=hi {
            res[i as usize] = pivot;
        }

        res
    }
}
