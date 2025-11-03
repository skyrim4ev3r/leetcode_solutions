impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {

        let mut res: Vec<i32> = Vec::new();

        for i in left..=right {

            let mut tmp = i;
            let mut is_divisible = true;

            while tmp > 0 {
                let digit = tmp % 10;
                if (digit == 0 || i % digit !=0) {
                    is_divisible = false;
                    break;
                }
                tmp /= 10;
            }

            if is_divisible {
                res.push(i);
            }
        }

        res
    }
}
