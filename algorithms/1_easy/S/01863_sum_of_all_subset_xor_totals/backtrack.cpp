class Solution {
    int backtrack(const size_t start, vector<int> &nums, const int parent_xor) {
        int sum{0};
        for (size_t i{start}; i < nums.size(); ++i) {
            int curr_xor = parent_xor ^ nums[i];
            sum += curr_xor;
            sum += backtrack(i + 1, nums, curr_xor);
        }

        return sum;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return backtrack(0, nums, 0);
    }
};
