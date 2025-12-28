class Solution {
public:
    static int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int res {nums[0] + nums[1] + nums[2]};
        const size_t len {nums.size()};

        for (size_t i {0}; i < len; ++i) {
            size_t left {i + 1};
            size_t right {len - 1};

            while (left < right) {
                const int temp {nums[i] + nums[left] + nums[right]};

                if (abs(res - target) > abs(temp - target)) {
                    res = temp;
                }

                if (temp < target) {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }

        return res;
    }
};
