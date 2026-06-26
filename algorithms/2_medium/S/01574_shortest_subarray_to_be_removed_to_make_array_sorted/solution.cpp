typedef ptrdiff_t isize;

class Solution {
    static inline isize custom_longest(span<const int> sorted_prefix, span<const int> sorted_suffix) {
        auto sub = vector<int>(sorted_prefix.cbegin(), sorted_prefix.cend());
        const isize sub_len = std::ssize(sub);
        const isize sorted_suffix_len = std::ssize(sorted_suffix);

        for (isize i = 0; i < sorted_suffix_len; i += 1) {
            const int a = sorted_suffix[i];
            isize hi = sub_len - 1;
            isize lo = 0;

            while (lo <= hi) {
                const isize mid = lo + (hi - lo) / 2;

                if (sub[mid] <= a) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (lo == sub_len) {
                // all remaining elems are sorted and can be added to current sub
                return (sorted_suffix_len - i) + sub_len;
            } else {
                sub[lo] = a;
            }
        }

        return sub_len;
    }

public:
    static int findLengthOfShortestSubarray(const vector<int>& arr) {
        const isize len = std::ssize(arr);
        if (len <= 1) { return 0; }
        isize hi = len - 1;
        isize lo = 0;

        while (hi > 0 && arr[hi - 1] <= arr[hi]) {
            hi -= 1;
        }

        if (hi == 0) {
            return 0;
        }

        while (arr[lo] <= arr[lo + 1]) {
            lo += 1;
        }

        auto sorted_prefix = span<const int>(arr.data(), lo + 1);
        auto sorted_suffix = span<const int>(arr.data() + hi, len - hi); cout<<custom_longest(sorted_prefix, sorted_suffix);

        return static_cast<int>(len - custom_longest(sorted_prefix, sorted_suffix));
    }
};
