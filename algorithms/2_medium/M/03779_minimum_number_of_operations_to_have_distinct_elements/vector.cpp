class Solution {
    static void normalize_the_vec(vector<int>& nums) {
        const int min_elem{ *ranges::min_element(nums) };

        for (auto& num : nums) {
            num -= min_elem;
        }
    }
public:
    static int minOperations(vector<int> nums) {
        const size_t len{ nums.size() };
        normalize_the_vec(nums);
        const int max_elem{ *ranges::max_element(nums) };
        vector<bool> seen(static_cast<size_t>(max_elem + 1), false);

        for (size_t i{ len - 1 }; i < len; --i) {
            if (seen[static_cast<size_t>(nums[i])]) {
                return static_cast<int>((i / 3) + 1);
            }
            seen[static_cast<size_t>(nums[i])] = true;
        }

        return 0;
    }
};
