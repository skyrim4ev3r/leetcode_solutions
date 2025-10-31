class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        size_t len{nums.size()};
        int half{static_cast<int>(len) / 2};
        int count{1};

        for (size_t i{1}; i < len; ++i) {
            if (nums[i - 1] == nums[i]) {
                count += 1;
            } else {
                count = 1;
            }

            if (count > half) {
                return nums[i];
            }
        }

        return nums[0];

    }
};
