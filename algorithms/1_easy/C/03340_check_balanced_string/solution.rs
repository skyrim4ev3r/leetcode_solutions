impl Solution {
    pub fn is_balanced(num: String) -> bool {
        let mut balance = 0;

        for (i, &byte) in num.as_bytes().iter().enumerate() {
            if (i & 1) == 1 {
                balance += (byte - b'0') as i32;
            } else {
                balance -= (byte - b'0') as i32;
            }
        }

        balance == 0
    }
}
