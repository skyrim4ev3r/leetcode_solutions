class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        size_t right{nums.size() - 1};
        size_t left{0};

        while (left < right) {
            const size_t mid{(left + right) / 2};

            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return static_cast<int>(left);
    }
};
