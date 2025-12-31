impl Solution {
    #[inline]
    fn are_lefthalf_righthalf_same(word: &[u8]) -> bool {
        if word.len() % 2 == 1 {
            return false;
        }

        let half = word.len() / 2;

        for i in 0..half {
            if word[i] != word[i + half] {
                return false;
            }
        }

        true
    }

    pub fn num_of_pairs(nums: Vec<String>, target: String) -> i32 {
        let target_len = target.len();
        let lefthalf_righthalf_are_same = Self::are_lefthalf_righthalf_same(target.as_bytes());
        let mut counts_starts_with = vec![0; target_len];
        let mut counts_ends_with = vec![0; target_len];
        let mut count = 0_i32;

        for num in nums.iter() {
            if num.len() < target_len {
                if target.starts_with(num) {
                    counts_starts_with[num.len()] += 1;
                }

                if target.ends_with(num) {
                    counts_ends_with[num.len()] += 1;
                }
            }
        }

        for i in 1..target_len {
            if lefthalf_righthalf_are_same && i == target_len - i {
                count += (counts_starts_with[i] - 1) * (counts_ends_with[target_len - i]);
            } else {
                count += counts_starts_with[i] * counts_ends_with[target_len - i];
            }
        }

        count
    }
}
