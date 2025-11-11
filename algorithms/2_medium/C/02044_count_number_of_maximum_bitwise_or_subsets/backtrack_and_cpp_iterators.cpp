class Solution {
    void subsets_backtrack(vector<int> &nums, int curr_or, size_t start_index, int max_or, int &count) {
        const size_t len = nums.size();

        if (curr_or == max_or) {
            count += std::pow(2, (len - start_index));
            return;
        }

        for (size_t i{start_index}; i < len; ++i) {
            subsets_backtrack(nums, curr_or | nums[i], i + 1, max_or, count);
        }
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {        
        int max_or{0};
        int count{0};

        for (const int &num: nums) {
            max_or |= num;
        }

        subsets_backtrack(nums, 0, 0, max_or, count);

        return count;
    }
};
