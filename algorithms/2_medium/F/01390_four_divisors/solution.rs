impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {

        let mut res = 0_i32;

        for num in nums.into_iter() {

            let sq = (num as f64).sqrt() as i32;
            let mut count = 0_i32;
            let mut sum = 0_i32;

            for i in 1..=sq {
                if num % i == 0 {
                    let other = num / i;

                    if i == other {
                        sum += i;
                        count += 1;
                    } else {
                        sum += i + other;
                        count += 2;
                    }

                    if count > 4 {
                        break;
                    }
                }
            }

            if count == 4 {
                res += sum;
            }
        }

        res
    }
}
