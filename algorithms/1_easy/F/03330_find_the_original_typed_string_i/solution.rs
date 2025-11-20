impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        let mut res = 0_i32;

        for w in word.as_bytes().windows(2) {
            if w[1] == w[0] {
                res += 1;
            }
        }

        // The total count of segments is the number of duplicates found (res) plus one
        // for the initial group of characters in the string
        res + 1
    }
}
