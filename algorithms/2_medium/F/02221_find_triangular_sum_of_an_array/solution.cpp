class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() != 1) {
            for (auto it{nums.begin()}; it != nums.end() - 1; ++it) {
                *it += *(it + 1);
                if (*it >= 10) {
                    *it -= 10;
                }
            }

            nums.pop_back();
        }

        return nums[0];
    }
};
