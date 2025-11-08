impl Solution {
    pub fn min_sensors(n: i32, m: i32, k: i32) -> i32 {        
        let w = 2 * k + 1;
        ((n + w - 1) / w) * ((m + w - 1) / w)
    }
}
