impl Solution {
    const MOD_TO: i64 = 1_000_000_007;

    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let len = complexity.len();

        for i in 1..len {
            if complexity[i] <= complexity[0] {
                return 0;
            }
        }

        let mut count = 1_i64;

        for i in 2..(len as i64) {
            count = (count * i) % Self::MOD_TO;
        }

        count as i32
    }
}
