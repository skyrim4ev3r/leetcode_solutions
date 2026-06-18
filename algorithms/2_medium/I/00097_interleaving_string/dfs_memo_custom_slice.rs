use std::marker::PhantomData;

#[derive(Copy, Clone)]
struct Slice2d<'a, T> {
    data: *mut T,
    rows: usize,
    cols: usize,
    _marker: PhantomData<&'a mut T>,
}

impl<'a, T> Slice2d<'a, T> {
    pub fn new(data: &mut [T], rows: usize, cols: usize) -> Self {
        assert!(data.len() >= rows * cols);
        Slice2d {
            data: data.as_mut_ptr(),
            rows,
            cols,
            _marker: PhantomData,
        }
    }

    #[inline(always)]
    pub unsafe fn get_unchecked(&self, row: usize, col: usize) -> &T {
        &*self.data.add(row * self.cols + col)
    }

    #[inline(always)]
    pub unsafe fn get_unchecked_mut(&self, row: usize, col: usize) -> &mut T {
        &mut *self.data.add(row * self.cols + col)
    }

    pub fn get(&self, row: usize, col: usize) -> &T {
        assert!(row < self.rows && col < self.cols);
        unsafe { self.get_unchecked(row, col) }
    }

    pub fn get_mut(&self, row: usize, col: usize) -> &mut T {
        assert!(row < self.rows && col < self.cols);
        unsafe { self.get_unchecked_mut(row, col) }
    }
}

impl Solution {
    fn dfs(
        b1: &[u8],
        b1_idx: usize,
        b2: &[u8],
        b2_idx: usize,
        b3: &[u8],
        b3_idx: usize,
        memo: Slice2d<bool>,
    ) -> bool {
        let (b1_len, b2_len, b3_len) = (b1.len(), b2.len(), b3.len());

        if b3_idx == b3_len {
            return true;
        }

        if !memo.get(b1_idx, b2_idx) {
            return false;
        }

        if b1_idx < b1_len && b1[b1_idx] == b3[b3_idx] {
            if Self::dfs(b1, b1_idx + 1, b2, b2_idx, b3, b3_idx + 1, memo) {
                return true;
            }
        }

        if b2_idx < b2_len && b2[b2_idx] == b3[b3_idx] {
            if Self::dfs(b1, b1_idx, b2, b2_idx + 1, b3, b3_idx + 1, memo) {
                return true;
            }
        }

        *memo.get_mut(b1_idx, b2_idx) = false;
        false
    }

    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let (b1, b2, b3) = (s1.as_bytes(), s2.as_bytes(), s3.as_bytes());
        let (b1_len, b2_len, b3_len) = (b1.len(), b2.len(), b3.len());

        if b1_len + b2_len != b3_len {
            return false;
        }

        if b1_len == 0 || b2_len == 0 {
            return b3 == b1 || b3 == b2;
        }

        let mut buff = vec![true; (b1_len + 1) * (b2_len + 1)];
        let mut memo = Slice2d::new(&mut buff[..], b1_len + 1, b2_len + 1);

        Self::dfs(b1, 0, b2, 0, b3, 0, memo)
    }
}
