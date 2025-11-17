impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut mask = 1_i32;

        while mask < num {
            mask = (mask << 1) | 1;
        }

        mask ^ num
    }
}
