impl Solution {
    #[inline(always)]
    fn get_digits(mut num: i32) -> Vec<u8> {
        let mut digits: Vec<u8> = Vec::with_capacity(9);
        while num > 0 {
            digits.push((num % 10) as u8);
            num /= 10;
        }
        digits.reverse();
        digits
    }

    #[inline(always)]
    fn construct_number_from_digits(digits: &Vec<u8>) -> i32 {
        let mut res = 0_i32;

        for &d in digits.iter() {
            res = res * 10 + d as i32;
        }

        res
    }

    pub fn maximum_swap(num: i32) -> i32 {
        let mut digits = Self::get_digits(num);
        let digits_sort = {
            let mut digits_sort = digits.clone();
            digits_sort.sort_unstable_by(|a, b| b.cmp(&a));
            digits_sort
        };

        let len = digits.len();
        let mut left = 0_usize;

        while left < len && digits[left] == digits_sort[left] {
            left += 1;
        }

        if left == len {
            return num;
        }

        let mut right = len - 1;
        while digits[right] != digits_sort[left] {
            right -= 1;
        }

        (digits[left], digits[right]) = (digits[right], digits[left]);

        Self::construct_number_from_digits(&digits)
    }
}
