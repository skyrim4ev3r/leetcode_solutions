impl Solution {
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = land.len();
        let cols = land[0].len();
        let mut res: Vec<Vec<i32>> = Vec::new();

        for i_st in 0..rows {
            for j_st in 0..cols {
                if land[i_st][j_st] == 1 {
                    let mut i_en = i_st;
                    let mut j_en = j_st;

                    while i_en + 1 < rows && land[i_en + 1][j_st] == 1 {
                        i_en += 1;
                    }

                    while j_en + 1 < cols && land[i_st][j_en + 1] == 1 {
                        j_en += 1;
                    }

                    for i in i_st..=i_en {
                        for j in j_st..=j_en {
                            land[i][j] = 0;
                        }
                    }

                    res.push(vec![i_st as i32, j_st as i32, i_en as i32, j_en as i32]);
                }
            }
        }

        res
    }
}
