class Solution {
public:
    int findMin(vector<int>& nums) {

        size_t left{0};
        size_t right{nums.size() - 1};
        int min_val{INT_MAX};

        while (left <= right) {
            size_t mid{(right + left) / 2};

            if (nums[left] <= nums[mid]) {
                min_val = min(min_val, nums[left]);
                left = mid + 1;
            } else {
                min_val = min(min_val, nums[mid]);
                right = mid - 1;
            }
        }

        return min_val;
    }
};
