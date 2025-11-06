impl Solution {
    pub fn sum_of_multiples(n: i32) -> i32 {
        let mut sum = 0_i32;

        for i in 3..=n {
            if i % 3 == 0 || i % 5 == 0 || i % 7 == 0 {
                sum += i;
            }
        }

        sum
    }
}
