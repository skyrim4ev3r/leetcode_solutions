impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {

        let mut carry = 1_i32;

        for digit in digits.iter_mut().rev() {
            *digit += carry;
            carry = 0;

            if *digit > 9 {
                *digit -= 10;
                carry = 1;
            }

            if carry == 0 {
                break;
            }
        }

        // This case occurs when all digits are 9 (e.g., [9,9,9,9]), 
        // resulting in [0,0,0,0]. We push a 0 and set the first digit to 1.
        if carry == 1 {
            digits.push(0);
            digits[0] = 1;
        }

        digits
    }
}
