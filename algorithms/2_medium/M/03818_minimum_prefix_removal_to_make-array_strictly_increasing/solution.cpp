class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        const size_t len{ nums.size() };

        if (len <= 1) {
            return 0;
        }

        size_t index { len - 1 };

        while (index > 0 && nums[index] > nums[index - 1]) {
            index -= 1;
        }

        return static_cast<int>(index);
    }
};
