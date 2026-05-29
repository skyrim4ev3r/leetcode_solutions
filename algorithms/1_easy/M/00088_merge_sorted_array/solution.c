void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    ptrdiff_t k = (ptrdiff_t) m + (ptrdiff_t) n - 1;
    ptrdiff_t i = (ptrdiff_t) m - 1;
    ptrdiff_t j = (ptrdiff_t) n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i -= 1;
        } else {
            nums1[k] = nums2[j];
            j -= 1;
        }

        k -= 1;
    }

    // No need to copy remaining nums1 elements because they are already in place
    while (j >= 0) {
        nums1[k] = nums2[j];
        k -= 1;
        j -= 1;
    }
}