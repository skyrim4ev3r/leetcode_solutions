use std::collections::HashSet;

impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let len = nums.len();
        let exact = nums.into_iter().map(|x| x.into_bytes()).collect::<HashSet<_>>();
        let mut bytes = vec![b'0'; len];

        while exact.contains(&bytes) {
            let mut i = len - 1;
            bytes[i] += 1;

            while bytes[i] > b'1' {
                bytes[i] -= 2;

                if i > 0 {
                    bytes[i - 1] += 1;
                    i -= 1;
                } else {
                    break;
                }
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
