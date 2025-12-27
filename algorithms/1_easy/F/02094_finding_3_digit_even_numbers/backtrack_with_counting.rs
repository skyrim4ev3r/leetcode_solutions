impl Solution {
    fn backtrack(
        digits_count: &mut [i32; 10],
        res: &mut Vec<i32>,
        curr_num: i32,
        curr_depth: i32,
    ) {
        if curr_depth == 3 {
            if curr_num >= 100 && curr_num < 1000 && curr_num % 2 == 0 {
                res.push(curr_num);
            }

            return;
        }

        for i in 0..10 {
            if digits_count[i] > 0 {
                digits_count[i] -= 1;
                Self::backtrack(digits_count, res, curr_num * 10 + (i as i32), curr_depth + 1);
                digits_count[i] += 1;
            }
        }
    }

    pub fn find_even_numbers(mut digits: Vec<i32>) -> Vec<i32> {
        let mut digits_count = [0_i32; 10];

        for digit in digits.into_iter() {
            digits_count[digit as usize] += 1;
        }

        let mut res: Vec<i32> = Vec::new();

        Self::backtrack(&mut digits_count, &mut res, 0, 0);

        res
    }
}
