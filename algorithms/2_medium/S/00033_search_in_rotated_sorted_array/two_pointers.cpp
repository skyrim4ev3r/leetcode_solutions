class Solution {
public:
    int search(vector<int>& nums, int target) {

        const size_t len{nums.size()};
        size_t right{len - 1};
        size_t left{0};

        while (left <= right && left < len && right < len) {
            const size_t mid{(left + right) / 2};

            if (nums[mid] == target) {
                return static_cast<int>(mid);
            }

            if (nums[left] <= nums[mid]) {
                if (target <= nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target <= nums[right] && target >= nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
