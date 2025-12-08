impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut count = 0_i32;

        for a in 1..=n {
            for b in a..=n {
                let c_square = a * a + b * b;
                let possible_c = (c_square as f64).sqrt() as i32; 

                if possible_c > n {
                    break;
                }

                if possible_c * possible_c == c_square {
                    count += 2;
                }
            }
        }

        count
    }
}
