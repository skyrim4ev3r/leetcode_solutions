class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int &num: nums) {
            num *= num;
        }

        sort(nums.begin(), nums.end());

        const size_t len{nums.size()};
        const size_t plus_index{len / 2};
        long long res ={0};

        for (size_t i{0}; i < plus_index; ++i) {
            res -= static_cast<long long>(nums[i]);
        }

        for (size_t i{plus_index}; i < len; ++i) {
            res += static_cast<long long>(nums[i]);
        }

        return res;
    }
};
