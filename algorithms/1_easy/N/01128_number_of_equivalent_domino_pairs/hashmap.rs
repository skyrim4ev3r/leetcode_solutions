use std::collections::HashMap;

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {

        let mut hashmap: HashMap<(i32, i32), i32> = HashMap::new();

        for d in dominoes.into_iter() {
            let min = d[0].min(d[1]);
            let max = d[0].max(d[1]);
            *hashmap.entry((min, max)).or_insert(0) += 1;
        }

        hashmap.into_iter().map(|(_,val)| (val * (val - 1)) / 2).sum()
    }
}
