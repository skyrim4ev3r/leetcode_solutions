impl Solution {
    fn dfs(
        nums: &[i32],
        len: usize,
        curr_idx: usize,
        curr_sum: i32,
        target: i32,
        memo: &mut [bool],
    ) -> bool {
        if curr_sum == target {
            return true;
        }

        if curr_sum > target || curr_idx >= len {
            return false;
        }

        let memo_idx = curr_idx * (target as usize) + curr_sum as usize;

        if !memo[memo_idx] {
            return false;
        }

        let res = Self::dfs(nums, len, curr_idx + 1, curr_sum + nums[curr_idx], target, memo) ||
                  Self::dfs(nums, len, curr_idx + 1, curr_sum, target, memo);

        memo[memo_idx] = res;
        res
    }

    pub fn can_partition(nums: Vec<i32>) -> bool {
        assert!(nums.len() > 0 && nums.iter().all(|&n| n >= 0));
        let sum = if cfg!(debug_assertions) {
            nums.iter().try_fold(0_i32, |acc, &x| acc.checked_add(x)).expect("overflow")
        } else {
            nums.iter().map(|x| *x).sum::<i32>()
        };
        if (sum & 1) == 1 { return false; }
        let target = sum / 2;
        let mut memo = vec![true; nums.len() * target as usize + 1];

        Self::dfs(&nums, nums.len(), 0, 0, target, &mut memo)
    }
}
