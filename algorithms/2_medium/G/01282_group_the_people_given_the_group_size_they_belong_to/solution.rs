use std::collections::HashMap;

impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {

        let mut groups_map: HashMap<usize, Vec<i32>> = HashMap::new();
        let mut res: Vec<Vec<i32>> = Vec::new();

        for i in 0..group_sizes.len() {
            let g_size = group_sizes[i] as usize;
            groups_map.entry(g_size).or_insert(Vec::new()).push(i as i32);

            if groups_map[&g_size].len() == g_size {
                if let Some(vec) = groups_map.remove(&g_size) {
                    res.push(vec);
                }
            }
        }

        res
    }
}
