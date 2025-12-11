use std::collections::HashMap;

impl Solution {
    pub fn count_covered_buildings(n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        let mut rows_map: HashMap<i32, (i32, i32)> = HashMap::new();
        let mut cols_map: HashMap<i32, (i32, i32)> = HashMap::new();
        let mut count = 0_i32;

        for building in buildings.iter() {
            let row_map = rows_map.entry(building[0]).or_insert((building[1], building[1]));
            row_map.0 = row_map.0.min(building[1]);
            row_map.1 = row_map.1.max(building[1]);

            let col_map = cols_map.entry(building[1]).or_insert((building[0], building[0]));
            col_map.0 = col_map.0.min(building[0]);
            col_map.1 = col_map.1.max(building[0]);
        }

        for building in buildings.iter() {
            let i = building[0];
            let j = building[1];

            if rows_map[&i].0 < j && rows_map[&i].1 > j && cols_map[&j].0 < i && cols_map[&j].1 > i {
                count += 1;
            }
        }

        count
    }
}
