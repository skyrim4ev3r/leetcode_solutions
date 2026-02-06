class Solution {
public:
    static int minRemoval(vector<int>& nums, const int k) {
        ranges::sort(nums);

        const size_t len{ nums.size() };
        size_t left{ 0 };
        const long long k_i64{ static_cast<long long>(k) };
        size_t max_window{ 0 };

        for (size_t right{ 0 }; right < len; ++right) {
            // No need to use while
            // Using 'if' to keep window size as max_window
            if (static_cast<long long>(nums[left]) * k_i64 < static_cast<long long>(nums[right])) {
                left += 1;
            }

            max_window = std::max(max_window, right - left + 1);
        }

        return static_cast<int>(len - max_window);
    }
};
