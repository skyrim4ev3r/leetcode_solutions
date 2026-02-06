class Solution {
    static inline size_t find_smallest_index(const vector<int>& nums, const size_t len) {
        size_t left{ 0 };
        size_t right{ len - 1 };

        while (left < right) {
            const size_t mid{ left + (right - left) / 2 };

            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left += 1;

                if (nums[left - 1] > nums[left]) {
                    return left;
                }
            } else if (nums[mid] >= nums[left]) {
                left = mid + 1;

                if (nums[left - 1] > nums[left]) {
                    return left;
                }
            } else {
                right = mid - 1;

                if (nums[right] > nums[right + 1]) {
                    return right + 1;
                }
            }
        }

        return left;
    }
public:
    static bool search(const vector<int>& nums, int target) {
        const size_t len{ nums.size() };
        size_t min_index{ find_smallest_index(nums, len) };

        return std::binary_search(nums.cbegin(), nums.cbegin() + min_index, target) ||
               std::binary_search(nums.cbegin() + min_index, nums.cend(), target);
    }
};
