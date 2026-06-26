impl Solution {
    #[inline(always)]
    fn custom_longest(sorted_prefix: &[i32], sorted_suffix: &[i32]) -> usize {
        let mut sub = sorted_prefix.to_vec().into_boxed_slice();
        let sub_len = sub.len();
        let sorted_suffix_len = sorted_suffix.len();

        for (i, &a) in sorted_suffix.into_iter().enumerate() {
            let mut hi = sub_len as isize - 1;
            let mut lo = 0_isize;

            while lo <= hi {
                let mid = lo + (hi - lo) / 2;

                if sub[mid as usize] <= a {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if lo as usize == sub_len {
                // all remaining elems are sorted and can be added to current sub
                return (sorted_suffix_len - i) + sub_len;
            } else {
                sub[lo as usize] = a;
            }
        }

        sub_len
    }

    pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
        let len = arr.len();
        if len <= 1 { return 0; }
        let mut hi = len - 1;
        let mut lo = 0_usize;

        while hi > 0 && arr[hi - 1] <= arr[hi] {
            hi -= 1;
        }

        if hi == 0 {
            return 0;
        }

        while arr[lo] <= arr[lo + 1] {
            lo += 1;
        }

        let sorted_prefix = &arr[0..=lo];
        let sorted_suffix = &arr[hi..];

        (len - Self::custom_longest(sorted_prefix, sorted_suffix)).try_into().unwrap()
    }
}
