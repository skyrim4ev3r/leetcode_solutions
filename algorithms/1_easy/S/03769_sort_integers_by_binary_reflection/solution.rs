impl Solution {
    fn manual_rev_bin(mut num: i32) -> i32 {
        let mut rev = 0_i32;

        while num > 0 {
            rev = rev << 1;
            rev |= (num & 1);
            num = num >> 1;
        }

        rev
    }
    pub fn sort_by_reflection(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable_by(|a, b| {
            let rev_a = Self::manual_rev_bin(*a);
            let rev_b = Self::manual_rev_bin(*b);

            if rev_a == rev_b {
                return a.cmp(&b);
            }

            rev_a.cmp(&rev_b)
        });

        nums
    }
}
