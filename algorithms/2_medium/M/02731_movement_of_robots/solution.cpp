const long long MOD_TO{ 1'000'000'007 };

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const size_t len{ nums.size() };
        vector<long long> nums_i64(len, 0);
        const long long d_i64{ static_cast<long long>(d) };

        for (size_t i{ 0 }; i < len; ++i) {
            if (s[i] == 'R') {
                nums_i64[i] = static_cast<long long>(nums[i]) + d_i64;
            } else {
                nums_i64[i] = static_cast<long long>(nums[i]) - d_i64;
            }
        }

        ranges::sort(nums_i64);

        long long res{ 0 };
        long long prefix{ 0 };

        for (size_t i{ 1 }; i < len; ++i) {
            prefix += static_cast<long long>(i) * abs(nums_i64[i] - nums_i64[i - 1]);
            res = (res + prefix) % MOD_TO;
        }

        return res;
    }
};
