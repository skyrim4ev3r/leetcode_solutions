use std::collections::HashMap;

impl Solution {
    fn gcd(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }

    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for num in deck.iter() {
            *freqs.entry(*num).or_insert(0) += 1;
        }

        let mut gcd = 0;

        for (_, freq) in freqs.iter() {
            gcd = Self::gcd(*freq, gcd);
        }

        gcd > 1
    }
}
