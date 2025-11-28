impl Solution {
    fn dfs(
        new_edges: &Vec<Vec<i32>>,
        values: &Vec<i32>,
        is_seen: &mut Vec<bool>,
        k: i64,
        curr: i32,
        count: &mut i32,
    ) -> i64 {
        let mut val = values[curr as usize] as i64;
        is_seen[curr as usize] = true;

        for child in new_edges[curr as usize].iter() {
            if !is_seen[*child as usize] {
                val += Self::dfs(new_edges, values, is_seen, k, *child, count);
            }
        }

        if val % k == 0 {
            *count += 1;
            return 0;
        }

        val
    }

    pub fn max_k_divisible_components(n: i32, edges: Vec<Vec<i32>>, mut values: Vec<i32>, k: i32) -> i32 {
        let mut count = 0_i32;
        let mut new_edges: Vec<Vec<i32>> = vec![Vec::new(); n as usize];
        let mut is_seen = vec![false; n as usize];

        for edge in edges {
            new_edges[edge[0] as usize].push(edge[1]);
            new_edges[edge[1] as usize].push(edge[0]);
        }

        Self::dfs(&new_edges, &values, &mut is_seen, k as i64, 0, &mut count);

        count
    }
}
