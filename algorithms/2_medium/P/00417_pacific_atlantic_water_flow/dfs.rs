/*
    using two is_visited, one for atlantic ocean, one for pacific ocean

    dfs every cells that are reachable from """atlantic ocean"""
    dfs every cells that are reachable from """pacific ocean"""

    at final every cells in grid with is_visited = true in "both is_visited" are reachable from both side,
    and can add all of them to """result"""
*/

/*
    using two is_visited, one for atlantic ocean, one for pacific ocean

    dfs every cells that are reachable from """atlantic ocean"""
    dfs every cells that are reachable from """pacific ocean"""

    at final every cells in grid with is_visited = true in "both is_visited" are reachable from both side,
    and can add all of them to """result"""
*/

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, -1), (0, 1), (1, 0), (-1, 0)];

    fn dfs(
        heights: &Vec<Vec<i32>>,
        is_visited: &mut Vec<Vec<bool>>,
        rows: usize,
        cols: usize,
        i: usize,
        j: usize,
    ) {
        is_visited[i][j] = true;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] || heights[new_i][new_j] < heights[i][j] {
                continue;
            }

            Self::dfs(heights, is_visited, rows, cols, new_i, new_j)
        }
    }

    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = heights.len();
        let cols = heights[0].len();

        let mut pacific_is_visited = vec![vec![false; cols]; rows];
        let mut atlantic_is_visited = vec![vec![false; cols]; rows];

        for i in 0..rows {
            for j in 0..cols {
                if i == 0 || j == 0 {
                    Self::dfs(&heights, &mut pacific_is_visited, rows, cols, i, j);
                }

                if i == rows - 1 || j == cols - 1 {
                    Self::dfs(&heights, &mut atlantic_is_visited, rows, cols, i, j);
                }
            }
        }

        let mut res: Vec<Vec<i32>> = Vec::new();

        for i in 0..rows {
            for j in 0..cols {
                if atlantic_is_visited[i][j] && pacific_is_visited[i][j] {
                    res.push(vec![i as i32, j as i32]);
                }
            }
        }

        res
    }
}
