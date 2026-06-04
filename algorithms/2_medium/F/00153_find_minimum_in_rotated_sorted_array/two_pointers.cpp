class Solution {
public:
    static int findMin(const vector<int>& nums) {
        ptrdiff_t left = 0;
        ptrdiff_t right = static_cast<ptrdiff_t>(nums.size()) - 1;
        int min_val = numeric_limits<int>::max();

        while (left <= right) {
            const ptrdiff_t mid = left + (right - left) / 2;

            if (nums[left] <= nums[mid]) {
                min_val = std::min(min_val, nums[left]);
                left = mid + 1;
            } else {
                min_val = std::min(min_val, nums[mid]);
                right = mid - 1;
            }
        }

        return min_val;
    }
};
