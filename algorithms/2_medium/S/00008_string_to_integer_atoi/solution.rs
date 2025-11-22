impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut is_negative = false;
        let mut index = 0_usize;
        const INT_MIN_AS_i64: i64 = i32::MIN as i64;
        const INT_MAX_AS_i64: i64 = i32::MAX as i64;

        while index < len && bytes[index] == b' ' {
            index += 1;
        }

        if index == len {
            return 0;
        }

        if bytes[index] == b'-' {
            is_negative = true;
        }

        if bytes[index] == b'-' || bytes[index] == b'+' {
            index += 1;
        }

        let mut res = 0_i64;

        while index < len && bytes[index] >= b'0' && bytes[index] <= b'9' {
            res *= 10;
            res += (bytes[index] - b'0') as i64;
            index += 1;

            if is_negative && res * -1 < INT_MIN_AS_i64 {
                return i32::MIN;
            }

            if !is_negative && res > INT_MAX_AS_i64 {
                return i32::MAX;
            }
        }

        if is_negative {
            return (res * -1) as i32;
        }

        res as i32
    }
}
