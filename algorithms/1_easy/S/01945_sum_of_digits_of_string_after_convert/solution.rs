impl Solution {
    pub fn get_lucky(s: String, k: i32) -> i32 {
        let mut sum = 0_i32;

        for byte in s.into_bytes().into_iter() {
            let num = (byte - b'a' + 1) as i32;
            sum += num % 10 + num / 10;
        }

        for _ in 1..k {
            let mut tmp = 0;
            while sum > 0 {
                tmp += sum % 10;
                sum /= 10;
            }
            sum = tmp;
        }

        sum
    }
}
