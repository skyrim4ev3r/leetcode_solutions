class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res{0};
        const size_t len{nums.size()};
        const size_t sqrt_len{static_cast<size_t>(sqrt(len))};

        for (size_t i{1}; i <= sqrt_len; ++i) {
            if (len % i == 0) {
                int other_index = len / i;
                res += std::pow(nums[i - 1], 2);

                if (other_index != i) {
                    res += std::pow(nums[other_index - 1], 2);
                }
            }
        }

        return res;
    }
};
