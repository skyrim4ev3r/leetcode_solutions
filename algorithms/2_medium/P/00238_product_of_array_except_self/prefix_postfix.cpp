class Solution {
public:
    static vector<int> productExceptSelf(const vector<int>& nums) {
        ptrdiff_t len = std::ssize(nums);
        assert(len >= 2);
        auto res = vector<int>(len, 0);

        int prefix_product = 1;
        for (ptrdiff_t i = 0; i < len; i += 1) {
            res[i] = prefix_product;
            prefix_product *= nums[i];
        }

        int postfix_product = 1;
        for (ptrdiff_t i = len - 1; i >= 0; i -= 1) {
            res[i] *= postfix_product;
            postfix_product *= nums[i];
        }

        return res;
    }
};
