impl Solution {
    pub fn maximum_score(a: i32, b: i32, c: i32) -> i32 {
        let mut stones = [a, b, c];
        stones.sort();

        let [min, mid, max] = stones;

        ((max + min + mid) / 2).min(min + mid)
    }
}
