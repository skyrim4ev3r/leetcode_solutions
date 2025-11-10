class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count{0};
        int curr_max{nums[0]};

        for (auto it{nums.cbegin() + 1}; it != nums.cend(); ++it) {
            if (*it <= curr_max) {
                curr_max += 1;
                count += curr_max - *it;
            } else {
                curr_max = *it;
            }
        }

        return count;
    }
};
