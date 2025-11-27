impl Solution {
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut digits: Vec<i32> = Vec::with_capacity(6);
        let mut count = 0_i32;

        for i in low..=high {
            let mut temp = i;

            digits.resize(0, 0);

            while temp > 0 {
                digits.push(temp % 10);
                temp /= 10;
            }

            if (digits.len() & 1) == 1 {
                continue;
            }

            let half = digits.len() / 2;
            let left = digits[0..half].iter().sum::<i32>();
            let right = digits[half..].iter().sum::<i32>();

            if left == right {
                count += 1;
            }
        }

        count
    }
}
