impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn nearest_exit(maze: Vec<Vec<char>>, entrance: Vec<i32>) -> i32 {
        let mut stack_a: Vec<(usize, usize)> = Vec::new();
        let mut stack_b: Vec<(usize, usize)> = Vec::new();
        let rows = maze.len();
        let cols = maze[0].len();
        let start_i = entrance[0] as usize;
        let start_j = entrance[1] as usize;
        let mut is_visited = vec![vec![false; cols]; rows];

        stack_a.push((start_i, start_j));
        is_visited[start_i][start_j] = true;
        let mut count = 0_i32;

        while !stack_a.is_empty() {
            count += 1;
            while let Some((curr_i, curr_j)) = stack_a.pop() {
                for (dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (curr_i as isize + *dx) as usize;
                    let new_j = (curr_j as isize + *dy) as usize;

                    if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] || maze[new_i][new_j] == '+' {
                        continue;
                    }

                    if new_i == rows - 1 || new_j == cols - 1 || new_i == 0 || new_j == 0 {
                        return count;
                    }
                    
                    is_visited[new_i][new_j] = true;
                    stack_b.push((new_i, new_j));
                }
            }

            stack_a = stack_b;
            stack_b = Vec::new();
        }
        

        -1
    }
}
