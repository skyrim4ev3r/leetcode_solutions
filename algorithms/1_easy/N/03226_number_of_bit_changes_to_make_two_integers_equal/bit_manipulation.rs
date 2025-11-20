impl Solution {
    pub fn min_changes(n: i32, k: i32) -> i32 {
        if (n | k) != n {-1_i32} else {(n ^ k).count_ones() as i32}
    }
}
