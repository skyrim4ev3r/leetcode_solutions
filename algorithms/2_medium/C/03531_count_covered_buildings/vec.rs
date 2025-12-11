impl Solution {
    pub fn count_covered_buildings(n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        let mut rows_map = vec![(-1_i32, -1_i32); (n + 1) as usize];
        let mut cols_map = vec![(-1_i32, -1_i32); (n + 1) as usize];
        let mut count = 0_i32;

        for building in buildings.iter() {
            let x = building[0];
            let y = building[1];
            let i = x as usize;
            let j = y as usize;

            if rows_map[i].0 == -1 {
                rows_map[i].0 = y;
                rows_map[i].1 = y;
            } else {
                rows_map[i].0 = rows_map[i].0.min(y);
                rows_map[i].1 = rows_map[i].1.max(y);
            }

            if cols_map[j].0 == -1 {
                cols_map[j].0 = x;
                cols_map[j].1 = x;
            } else {
                cols_map[j].0 = cols_map[j].0.min(x);
                cols_map[j].1 = cols_map[j].1.max(x);
            }
        }

        for building in buildings.iter() {
            let x = building[0];
            let y = building[1];
            let i = x as usize;
            let j = y as usize;

            if rows_map[i].0 < y && rows_map[i].1 > y as i32 && cols_map[j].0 < x as i32 && cols_map[j].1 > x {
                count += 1;
            }
        }

        count
    }
}
