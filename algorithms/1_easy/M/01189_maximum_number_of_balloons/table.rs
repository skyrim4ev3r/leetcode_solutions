impl Solution {
    const TABLE_SIZE: usize = 256;

    fn max_formations_of(source: &[u8], target: &[u8]) -> i32 {
        if target.len() == 0 { return 0; }
        let mut freqs_source = [0_usize; Self::TABLE_SIZE];
        let mut freqs_target = [0_usize; Self::TABLE_SIZE];

        for &byte in source { freqs_source[byte as usize]  += 1; }
        for &byte in target { freqs_target[byte as usize]  += 1; }

        (0..Self::TABLE_SIZE).into_iter()
                       .filter(|i| freqs_target[*i] != 0)
                       .map(|i| freqs_source[i] / freqs_target[i])
                       .min()
                       .unwrap()
                       .try_into()
                       .unwrap()
    }

    pub fn max_number_of_balloons(text: String) -> i32 {
        Self::max_formations_of(text.as_bytes(), b"balloon")
    }
}
