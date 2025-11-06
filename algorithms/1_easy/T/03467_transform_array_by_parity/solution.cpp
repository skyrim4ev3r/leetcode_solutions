class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {

        int even_count{0};
        for (const int &num: nums) {
            if ((num & 1) == 0) {
                even_count += 1;
            }
        }

        const size_t len{nums.size()};
        for (int i{0}; i < len; ++i) {
            if (i < even_count) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }

        return nums;
    }
};
