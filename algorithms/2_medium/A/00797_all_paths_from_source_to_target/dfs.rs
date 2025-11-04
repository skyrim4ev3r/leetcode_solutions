impl Solution {
    fn dfs(graph: &Vec<Vec<i32>>, curr_index: usize, target_index: usize, curr_vec: &mut Vec<i32>, res: &mut Vec<Vec<i32>>) {       
        curr_vec.push(curr_index as i32);

        if curr_index == target_index {
            res.push(curr_vec.clone());
        } else {
            for &next_index in graph[curr_index].iter() {
                Self::dfs(graph, next_index as usize, target_index, curr_vec, res);
            }
        }

        curr_vec.pop();
    }

    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut temp_vec: Vec<i32> = Vec::with_capacity(graph.len());
        let target_index = graph.len() - 1;
        let start_index = 0_usize;

        Self::dfs(&graph, start_index, target_index, &mut temp_vec, &mut res);

        res
    }
}
