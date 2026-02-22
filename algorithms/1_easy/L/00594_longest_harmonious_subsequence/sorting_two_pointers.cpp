class Solution {
public:
    int findLHS(vector<int>& nums) {
        const size_t len{ nums.size() };
        size_t left{ 0 };
        size_t right{ 0 };
        size_t longest{ 0 };

        ranges::sort(nums);

        while (right < len) {
            while (nums[right] - nums[left] > 1) {
                left += 1;
            }

            while (right + 1 < len && nums[right + 1] - nums[left] <= 1) {
                right += 1;
            }

            if (nums[right] != nums[left]) {
                longest = std::max(longest, right - left + 1);
            }

            right += 1;
        }

        return static_cast<int>(longest);
    }
};
