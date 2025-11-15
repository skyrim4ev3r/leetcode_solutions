impl Solution {
    pub fn generate_the_string(n: i32) -> String {
        let mut vec = vec![b'a'; n as usize];

        if n % 2 == 0 {
            *vec.last_mut().unwrap() = b'b';
        }

        String::from_utf8(vec).unwrap()
    }
}
