impl Solution {
    #[inline(always)]
    fn is_palindrome(b: &[u8]) -> bool {
        let len = b.len();
        if len <= 1 { return true; }
        let mut lo = 0;
        let mut hi = len - 1;

        while lo < hi {
            if b[lo] != b[hi] {
                return false;
            }

            lo += 1;
            hi -= 1;
        }

        true
    }

    #[inline(always)]
    fn is_palindrome_by_split(b1: &[u8], b2: &[u8]) -> bool {
        assert!(b1.len() == b2.len());
        let len = b1.len();
        if len <= 1 { return true; }
        let mut lo = 0;
        let mut hi = len - 1;

        while lo < hi && b1[lo] == b2[hi] {
            lo += 1;
            hi -= 1;
        }

        Self::is_palindrome(&b1[lo..=hi]) || Self::is_palindrome(&b2[lo..=hi])
    }

    pub fn check_palindrome_formation(s1: String, s2: String) -> bool {
        let (b1, b2) = (s1.as_bytes(), s2.as_bytes());

        Self::is_palindrome_by_split(b1, b2) || Self::is_palindrome_by_split(b2, b1)
    }
}
