impl Solution {

    #[inline(always)]
    fn calc_final_res_len(bytes: &[u8]) -> i64 {
        let mut res_len = 0_i64;

        for &byte in bytes {
            match byte {
                b'#' => res_len *= 2,
                b'a'..=b'z' => res_len += 1,
                b'*' => res_len = 0_i64.max(res_len - 1),
                b'%' => {},
                _ => unreachable!("invalid input"),
            }
        }

        res_len
    }

    pub fn process_str(s: String, mut k: i64) -> char {
        assert!(k >= 0);
        let bytes = s.as_bytes();
        let mut res_len = Self::calc_final_res_len(bytes);
        if res_len <= k {
            return '.';
        }

        for &byte in bytes.into_iter().rev()  {
            match byte {
                b'#' => {
                    res_len /= 2;
                    if k >= res_len {
                        k -= res_len;
                    }
                },
                b'a'..=b'z' => {
                    res_len -= 1;
                    if res_len == k {
                        return byte as char;
                    }
                },
                b'*' => res_len += 1,
                b'%' => k = res_len - k - 1,
                _ => unreachable!("invalid input"),
            }
        }

        '.'
    }
}
