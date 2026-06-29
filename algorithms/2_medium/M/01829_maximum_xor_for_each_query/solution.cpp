typedef ptrdiff_t isize;

class Solution {
public:
    static vector<int> getMaximumXor(const vector<int>& nums, const int maximum_bit) {
        assert(maximum_bit <= 20 && maximum_bit >= 0);
        const int mask = (1 << maximum_bit) - 1;
        int total_xor = 0;
        const isize len = std::ssize(nums);
        auto res = vector<int>(len);

        for (isize i = 0; i < len; i += 1) {
            total_xor ^= nums[i];
            res[i] = mask ^ total_xor;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};
