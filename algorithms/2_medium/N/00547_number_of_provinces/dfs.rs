impl Solution {
    fn dfs(is_connected: &Vec<Vec<i32>>, is_seen: &mut Vec<bool>, n: usize, row: usize) {
        if is_seen[row] {
            return;
        }

        is_seen[row] = true;
        for i in 0..n {
            if is_connected[row][i] == 1 {
                Self::dfs(is_connected, is_seen, n, i);
            }
        }
    }

    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        let n = is_connected.len();
        let mut is_seen: Vec<bool> = vec![false; n];
        let mut count = 0_i32;

        for i in 0..n {
            if (!is_seen[i]) {
                count += 1;
                Self::dfs(&is_connected, &mut is_seen, n, i);
            }
        }

        count
    }
}
