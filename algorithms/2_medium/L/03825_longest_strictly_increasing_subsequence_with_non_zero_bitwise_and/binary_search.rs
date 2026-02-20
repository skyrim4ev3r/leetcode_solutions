impl Solution {
    const MAX_VALID_BIT: usize = 31;

    #[inline(always)]
    fn calc_lis_with_mask(nums: &Vec<i32>, mask: i32) -> i32 {
        let mut sub: Vec<i32> = Vec::new();

        for &num in nums {
            if (num & mask) == 0 {
                continue;
            }

            let pos = sub.binary_search(&num).unwrap_or_else(|x| x);
            if pos < sub.len() {
                sub[pos] = num;
            } else {
                sub.push(num);
            }
        }

        sub.len() as i32
    }

    pub fn longest_subsequence(nums: Vec<i32>) -> i32 {
        let mut longest = 0_i32;

        for i in 0..Self::MAX_VALID_BIT {
            let mask = 1 << i;

            longest = longest.max(Self::calc_lis_with_mask(&nums, mask));
        }

        longest
    }
}
