class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        size_t m_usize{static_cast<size_t>(m)};
        size_t n_usize{static_cast<size_t>(n)};

        size_t k{m_usize + n_usize - 1};
        size_t i{m_usize - 1};
        size_t j{n_usize - 1};

        while (i < m_usize && j < n_usize) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i -= 1;
            } else {
                nums1[k] = nums2[j];
                j -= 1;
            }
            k -= 1;
        }

        while (j < n_usize) {
            nums1[k] = nums2[j];
            k -= 1;
            j -= 1;
        }
    }
};
