use std::cmp::Reverse;

#[derive(Default, Clone, Copy)]
struct Entity {
    freq: i32,
    byte: u8,
}

impl Solution {
    const VOWELS_LEN: usize = 5;

    #[inline(always)]
    fn is_vowel(byte: u8) -> bool {
        matches!(byte, b'a' | b'e' | b'i' | b'o' | b'u')
    }

    #[inline(always)]
    fn inc_freq(table: &mut[Entity], table_len: usize, byte: u8) -> bool {
        for i in 0..table_len {
            if table[i].byte == byte {
                table[i].freq += 1;
                return true;
            }
        }

        false
    }

    pub fn sort_vowels(s: String) -> String {
        let mut bytes = s.into_bytes();
        let mut table = [Entity::default(); Self::VOWELS_LEN];
        let mut table_len = 0_usize;

        for &byte in bytes.iter() {
            if Self::is_vowel(byte) {
                if !Self::inc_freq(&mut table, table_len, byte) {
                    assert!(table_len < Self::VOWELS_LEN);
                    table[table_len] =  Entity{ freq: 1, byte: byte};
                    table_len += 1;
                }
            }
        }

        table[0..table_len].sort_by_key(|x| Reverse(x.freq));
        let mut table_idx = 0;
        for byte in bytes.iter_mut() {
            if Self::is_vowel(*byte) {
                *byte = table[table_idx].byte;
                table[table_idx].freq -= 1;
                if table[table_idx].freq == 0 {
                    table_idx += 1;
                }
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
