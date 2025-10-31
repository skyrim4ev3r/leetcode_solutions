impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {

        if n.count_ones() != 1 {
            return false;
        }

        for i in 0..32 {
            if n & (1 << i) != 0 {
                return (i & 1) == 0;
            }
        }

        false
    }
}
