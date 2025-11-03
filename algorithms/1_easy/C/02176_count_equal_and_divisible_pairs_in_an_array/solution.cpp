class Solution {
public:
    int countPairs(vector<int>& nums, int k) {        
        const size_t nums_len{nums.size()};
        int count{0};

        for (size_t i{0}; i < nums_len; ++i) {
            for (size_t j{i + 1}; j < nums_len; ++j) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
