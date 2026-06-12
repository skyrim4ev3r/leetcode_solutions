impl Solution {
    pub fn is_power_of_three(mut n: i32) -> bool {
        const max_int_pow_3: i32 = 1162261467;
        
        n > 0 && max_int_pow_3 % n == 0
    }
}
