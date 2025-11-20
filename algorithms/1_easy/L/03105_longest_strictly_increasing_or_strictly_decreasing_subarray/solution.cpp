class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest{1};
        int curr{0};
        const size_t len{nums.size()};
        int state{0};

        for (size_t i{1}; i < len; ++i) {
            if (nums[i] > nums[i - 1]) {
                if (state != 1) {
                    curr = 2;
                    state = 1;
                } else {
                    curr += 1;
                }
            } else if (nums[i] < nums[i - 1]) {
                if (state != -1) {
                    curr = 2;
                    state = -1;
                } else {
                    curr += 1;
                }
            } else {
                state = 0;
                curr = 1;
            }

            longest = std::max(longest, curr);
        }

        return longest;
    }
};
