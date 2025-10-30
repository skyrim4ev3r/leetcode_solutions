impl Solution {
    fn backtrack(res: &mut Vec<Vec<i32>>, candidates: &Vec<i32>, curr_vec: &mut Vec<i32>, start_pos: usize, target: i32) {
        if target == 0 {
            res.push(curr_vec.clone());
            return;
        }
        
        let candidates_len = candidates.len();

        if start_pos ==  candidates_len {
            return;
        }

        for i in start_pos..candidates_len {
            if i != start_pos && candidates[i] == candidates[i - 1] {
                continue;
            } 
            
            if (target - candidates[i] < 0) {
                break;
            } 
            
            curr_vec.push(candidates[i]);
            Self::backtrack(res, candidates, curr_vec, i + 1, target - candidates[i]);
            curr_vec.pop();
        }
    }

    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {

        candidates.sort_unstable();

        let mut res: Vec<Vec<i32>> = Vec::new(); 
        let mut curr_vec: Vec<i32> = Vec::new(); 

        Self::backtrack(&mut res, & candidates, &mut curr_vec, 0_usize, target);

        res
    }
}
