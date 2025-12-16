impl Solution {
    fn backtrack(freqs: &mut Vec<u8>, len: usize) ->i32 {
        let mut count = 0_i32;

        for i in 0..len {
            if freqs[i] != 0 {
                freqs[i] -= 1;
                count += 1 + Self::backtrack(freqs, len);
                freqs[i] += 1;
            }
        }

        count
    }

    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut freqs = [0_u8; 26];

        for byte in tiles.as_bytes().iter() {
            freqs[(*byte - b'A') as usize] += 1;
        }

        let mut valid_freqs = freqs.iter().filter(|x| **x > 0).map(|x| *x).collect::<Vec<u8>>();
        let len =  valid_freqs.len();

        Self::backtrack(&mut valid_freqs, len)
    }
}
