impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [
        (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)
    ];

    const board_size: usize = 8;

    pub fn queens_attackthe_king(queens: Vec<Vec<i32>>, king: Vec<i32>) -> Vec<Vec<i32>> {
        let mut board = [[false; Self::board_size]; Self::board_size];
        let mut res: Vec<Vec<i32>> = Vec::new();

        for q in queens.into_iter() {
            board[q[0] as usize][q[1] as usize] = true;
        }

        let i_st = king[0] as usize;
        let j_st = king[1] as usize;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let mut i = (i_st as isize + dx) as usize;
            let mut j = (j_st as isize + dy) as usize;

            while i < Self::board_size && j < Self::board_size {
                if board[i][j] {
                    res.push(vec![i as i32, j as i32]);
                    break;
                }

                i = (i as isize + dx) as usize;
                j = (j as isize + dy) as usize;
            }
        }

        res
    }
}
