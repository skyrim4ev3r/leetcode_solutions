impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let (mut i1, mut j1, mut i2, mut j2) = (0_usize, 0_usize, 0_usize, 0_usize);
        let (row1, row2) = (word1.len(), word2.len());

        while i1 < row1 && i2 < row2 {
            if word1[i1].as_bytes()[j1] != word2[i2].as_bytes()[j2] {
                return false;
            }

            j1 += 1;
            j2 += 1;

            if j1 == word1[i1].len() {
                i1 += 1;
                j1 = 0;
            }

            if j2 == word2[i2].len() {
                i2 += 1;
                j2 = 0;
            }
        }

        i1 == row1 && i2 == row2
    }
}
