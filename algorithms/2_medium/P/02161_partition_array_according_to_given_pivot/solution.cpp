class Solution {
public:
    static vector<int> pivotArray(const vector<int>& nums, int pivot) {
        const ptrdiff_t len = nums.size();
        assert(len > 0);
        auto res = vector<int>(len, 0);
        ptrdiff_t lo = 0;
        ptrdiff_t hi = len - 1;

        for (const auto num : nums) {
            if (num < pivot) {
                res[lo] = num;
                lo += 1;
            } else if (num > pivot) {
                res[hi] = num;
                hi -= 1;
            }
        }

        std::reverse(res.begin() + (hi + 1), res.end());

        for (ptrdiff_t i = lo; i <= hi; i += 1) {
            res[i] = pivot;
        }

        return res;
    }
};
