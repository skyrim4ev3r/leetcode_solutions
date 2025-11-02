impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [(0, -1), (0, 1), (1, -1), (1, 0), (1, 1), (-1, -1), (-1, 0), (-1, 1)];

    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = img.len();
        let cols = img[0].len();

        let mut res: Vec<Vec<i32>> = vec![vec![0_i32; cols]; rows];

        for i in 0..rows {
            for j in 0..cols {
                let mut sum = img[i][j];
                let mut count = 1_i32;

                for &(dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (i as isize + dx) as usize;
                    let new_j = (j as isize + dy) as usize;

                    if new_i >= rows || new_j >= cols {
                        continue;
                    }

                    count += 1;
                    sum += img[new_i][new_j];
                }
                
                res[i][j] = sum / count;
            }
        }

        res
    }
}
