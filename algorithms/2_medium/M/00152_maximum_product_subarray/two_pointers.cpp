class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const size_t len{ nums.size() };
        size_t left{ 0 };
        int prod{ 1 };
        int max_prod{ numeric_limits<int>::min() };

        for (size_t right{ 0 }; right < len; ++right) {
            if (nums[right] == 0) {
                max_prod = std::max(max_prod, 0);
                left = right + 1;
                prod = 1;
            } else {
                prod *= nums[right];
                max_prod = std::max(max_prod, prod);

                if (right + 1 == len || nums[right + 1] == 0) {
                    while (left < right) {
                        prod /= nums[left];
                        max_prod = std::max(max_prod, prod);
                        left += 1;
                    }
                }
            }
        }

        return max_prod;
    }
};
