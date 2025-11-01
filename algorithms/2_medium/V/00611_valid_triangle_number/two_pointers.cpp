class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        size_t sum{0};
        const size_t len{nums.size()};

        sort(nums.begin(), nums.end());

        for (size_t i{2}; i < len; ++i) {

            size_t left{0};
            size_t right{i - 1};

            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    // Add all triplets
                    // nums[left..=right - 1], nums[right], nums[i]
                    sum += right - left;
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }

        return static_cast<int>(sum);
    }
};
