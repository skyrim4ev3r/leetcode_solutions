impl Solution {
    const MIN_ALLOWED_NUM: i32 =  0;
    const MAX_ALLOWED_NUM: i32 = 500;
    const NUMS_DIFF: usize = (Self::MAX_ALLOWED_NUM - Self::MIN_ALLOWED_NUM + 1) as usize;

    pub fn longest_arith_seq_length(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 2 { return len as i32; }

        let mut dp = vec![0_i32; 2 * Self::NUMS_DIFF * len];
        let (mut pos, mut neg) = dp.split_at_mut(Self::NUMS_DIFF * len);
        let mut res = 0_i32;

        for i in (0..len).rev() {
            assert!(nums[i] >= Self::MIN_ALLOWED_NUM && nums[i] <= Self::MAX_ALLOWED_NUM);
            let idx_i = i * Self::NUMS_DIFF;
            for j in ((i + 1)..len).rev() {
                let idx_j = j * Self::NUMS_DIFF;
                let diff = nums[i] - nums[j];
                let prev = if diff < 0 { neg[idx_j + (-diff) as usize] } else { pos[idx_j + diff as usize] };
                let curr = (prev + 1).max(2);
                let mut curr_ref = if diff < 0 { &mut neg[idx_i + (-diff) as usize] } else { &mut pos[idx_i + diff as usize] };
                *curr_ref = (*curr_ref).max(curr);
                res = res.max(curr);
            }
        }

        res
    }
}
