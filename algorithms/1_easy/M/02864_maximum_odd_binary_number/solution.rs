impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let mut s_bytes = s.into_bytes();
        let mut ones = s_bytes.iter().filter(|x| **x == b'1').count();

        ones -= 1; // reserve 1x one for last byte

        for it in s_bytes.iter_mut() {
            if ones > 0 {
                *it = b'1';
                ones -= 1;
            } else {
                *it = b'0';
            }
        }

        *s_bytes.last_mut().unwrap() = b'1'; // using that 1x reserved one

        String::from_utf8(s_bytes).unwrap()
    }
}
