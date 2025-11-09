class Solution {
    int backtrack(const vector<int>::const_iterator it_start, vector<int> &nums, const int parent_xor) {
        int sum{0};
        for (auto it{it_start}; it != nums.cend(); ++it) {
            int curr_xor = parent_xor ^ *it;
            sum += curr_xor;
            sum += backtrack(it + 1, nums, curr_xor);
        }

        return sum;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums.cbegin(), nums, 0);
    }
};
