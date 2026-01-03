use std::collections::HashMap;

impl Solution {
    pub fn query_results(limit: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let len = queries.len();
        let mut res: Vec<i32> = Vec::with_capacity(len);
        let mut freqs_colors: HashMap<i32, i32> = HashMap::new();
        let mut curr_colors: HashMap<i32, i32> = HashMap::new();

        for q in queries.into_iter() {
            let x = q[0];
            let new_color = q[1];

            if let Some(old_color) = curr_colors.get(&x) {
                let freq = freqs_colors.get_mut(&old_color).unwrap();

                *freq -= 1;

                if *freq == 0 {
                    freqs_colors.remove(&old_color);
                }
            }

            *curr_colors.entry(x).or_insert(0) = new_color;
            *freqs_colors.entry(new_color).or_insert(0) += 1;

            res.push(freqs_colors.len() as i32)
        }

        res
    }
}
