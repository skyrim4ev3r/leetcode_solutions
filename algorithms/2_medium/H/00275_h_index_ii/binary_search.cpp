class Solution {
public:
    static int hIndex(const vector<int>& citations) {
        const ptrdiff_t len = std::ssize(citations);
        assert(len > 0);
        ptrdiff_t lo = 0;
        ptrdiff_t hi = len - 1;
        int res = 0;

        while (lo <= hi) {
            const ptrdiff_t mid = lo + (hi - lo) / 2;
            const int least_valid = static_cast<int>(len - mid);

            if (citations[mid] >= least_valid) {
                res = least_valid;
                hi = mid - 1;
            } else {
                lo = mid +1;
            }
        }

        return res;
    }
};
