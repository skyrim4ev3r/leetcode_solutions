class Solution {
public:
    static int minSubArrayLen(const int target, const vector<int>& nums) {
        assert(nums.size() > 0);
        assert(target > 0);

        const size_t len = nums.size();
        size_t min_width = len + 1;
        size_t left = 0;
        int curr_sum = 0;

        for (size_t right = 0; right < len; right += 1) {
            assert(nums[right] > 0);
            assert(numeric_limits<int>::max() - nums[right] >= curr_sum);
            curr_sum += nums[right];

            while (left <= right && curr_sum >= target) {
                min_width = std::min(min_width, right - left + 1);
                curr_sum -= nums[left];
                left += 1;
            }
        }

        return static_cast<int>(min_width == len + 1 ? 0 : min_width);
    }
};
