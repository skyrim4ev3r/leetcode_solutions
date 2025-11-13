impl Solution {
    fn backtrack(
        res: &mut Vec<Vec<i32>>,
        tmp: &mut Vec<i32>,
        candidates: &Vec<i32>,
        candidates_len: usize,
        curr_index: usize,
        target: i32,
    ) {
        if target == 0 {
            res.push(tmp.clone());
            return;
        }

        for i in curr_index..candidates_len {
            if target - candidates[i] >= 0 {
                tmp.push(candidates[i]);
                Self::backtrack(res, tmp, candidates, candidates_len, i, target - candidates[i]);
                tmp.pop();
            } else {
                break;
            }
        }
    }

    pub fn combination_sum(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut tmp: Vec<i32> = Vec::new();

        candidates.sort_unstable();
        Self::backtrack(&mut res, &mut tmp, &candidates, candidates.len(), 0, target);

        return res;
    }
}
