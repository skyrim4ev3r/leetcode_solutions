class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const size_t len{ nums.size() };
        size_t res_len{ len + 1 };
        size_t left{ 0 };
        int curr_sum{ 0 };

        for (size_t right{ 0 }; right < len; ++right) {
            curr_sum += nums[right];

            while (left <= right && curr_sum >= target) {
                res_len = std::min(res_len, right - left + 1);
                curr_sum -= nums[left];
                left += 1;
            }
        }

        if (res_len == len + 1) {
            return 0;
        }

        return static_cast<int>(res_len);
    }
};
