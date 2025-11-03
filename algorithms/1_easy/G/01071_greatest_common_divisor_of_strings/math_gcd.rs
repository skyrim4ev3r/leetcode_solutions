impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {

        if str1.clone() + &str2 != str2.clone() + &str1 {
            return String::new();
        }

        let str1_bytes = str1.into_bytes();
        let str2_bytes = str2.into_bytes();

        fn gcd(a: usize, b: usize) -> usize {
            if b == 0 { a } else { gcd(b, a % b) }
        }

        let length_gcd = gcd(str1_bytes.len(), str2_bytes.len());

        String::from_utf8_lossy(&str1_bytes[..length_gcd]).into_owned()
    }
}
