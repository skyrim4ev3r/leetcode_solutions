use std::collections::HashMap;

impl Solution {
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut hashmap: HashMap<Vec<i32>, i32> = HashMap::new();
        let mut temp: Vec<i32> = vec![0_i32; n];
        let mut count = 0_i32;

        for j in 0..n {
            for i in 0..n {
                temp[i] = grid[i][j];
            }

            if let Some(count) = hashmap.get_mut(&temp) {
                *count += 1;
            } else {
                hashmap.insert(temp.clone(), 1);
            }
        }

        for row in grid.into_iter() {
            if let Some(val) = hashmap.get(&row) {
                count += *val;
            }
        }

        count
    }
}
