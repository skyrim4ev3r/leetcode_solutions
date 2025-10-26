class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t nums_len{nums.size()};
        vector<int> res (nums_len, 0);

        int prefix_product{1};
        for (size_t i{0}; i < nums_len; ++i) {
            res[i] = prefix_product;
            prefix_product *= nums[i];
        }

        int postfix_product{1};
        for (size_t i{nums_len - 1}; i < nums_len; --i) {
            res[i] *= postfix_product;
            postfix_product *= nums[i];
        }

        return res;
    }
};
