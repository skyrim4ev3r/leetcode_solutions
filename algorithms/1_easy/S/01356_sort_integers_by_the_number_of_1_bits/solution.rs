impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort_unstable_by(|a, b| {
            let a_count_ones = a.count_ones();
            let b_count_ones = b.count_ones();

            if a_count_ones == b_count_ones {a.cmp(&b)} else {a_count_ones.cmp(&b_count_ones)}
        });

        arr
    }
}
