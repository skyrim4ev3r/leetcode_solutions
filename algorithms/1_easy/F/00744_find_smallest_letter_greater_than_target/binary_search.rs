impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let pos = letters.binary_search(&((target as u8 + 1) as char)).unwrap_or_else(|x| x);

        if pos == letters.len() {
            return letters[0];
        }

        letters[pos]
    }
}
