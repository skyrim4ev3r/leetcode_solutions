impl Solution {
    pub fn check_divisibility(n: i32) -> bool {
        let mut temp = n;
        let mut sum = 0_i32;
        let mut mul = 1_i32;

        while temp > 0 {
            let digit = temp % 10;
            sum += digit;
            mul *= digit;
            temp /= 10;
        }

        n % (sum + mul) == 0
    }
}
