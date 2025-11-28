impl Solution {
    pub fn total_waviness(num1: i32, num2: i32) -> i32 {
        let mut digits: Vec<i32> = Vec::with_capacity(6);
        let mut count = 0_i32;

        for i in num1..=num2 {
            let mut temp = i;
            digits.clear();

            while temp > 0 {
                digits.push(temp % 10);
                temp /= 10;
            }

            for w in digits.windows(3) {
                if (
                    (w[1] > w[0] && w[1] > w[2]) ||
                    (w[1] < w[0] && w[1] < w[2])
                ) {
                    count += 1;
                }
            }
        }

        count
    }
}
