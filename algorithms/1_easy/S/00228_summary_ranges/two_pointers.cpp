class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const size_t len{nums.size()};

        vector<string> res;

        // This 'if' is optional; the code logic can handle len of 0. 
        // It's just for clarity and early exit.
        if (len == 0) {
            return res;
        }

        size_t left{0};
        size_t right{1};

        while (right <= len) {
            while (right < len && nums[right - 1] + 1 == nums[right]) {
                right += 1;
            }

            if (left + 1 == right) {
                res.push_back(to_string(nums[left]));
            } else {
                res.push_back(to_string(nums[left])+"->"+to_string(nums[right - 1]));
            }

            left = right;
            right += 1;
        }

        return res;
    }
};
