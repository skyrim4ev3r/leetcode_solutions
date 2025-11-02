impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {

        let n_usize = n as usize;
        let m_usize = m as usize;
        let mut k = m_usize + n_usize - 1;
        let mut i = m_usize - 1;
        let mut j = n_usize - 1;

        while i < m_usize && j < n_usize {
            if nums1[i] > nums2[j] {
                nums1[k] = nums1[i];
                i -= 1;
            } else {
                nums1[k] = nums2[j];
                j -= 1;
            }
            k -= 1;
        }

        while j < n_usize {
            nums1[k] = nums2[j];
            k -= 1;
            j -= 1;
        }
    }
}
