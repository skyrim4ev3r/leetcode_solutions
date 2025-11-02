impl Solution {
    pub fn check_perfect_number(num: i32) -> bool {
        if num == 1 {
            return false;
        }

        let mut sum = 1;
        let sq = (num as f64).sqrt() as i32;

        for i in 2..=sq {
            if num % i == 0 {
                sum += i;

                if i != sq {
                    sum += num/i;
                } else if i * i != num {
                    sum += num/i;
                }

                if sum > num {
                    break;
                }
            }
        }

        sum == num
    }
}
