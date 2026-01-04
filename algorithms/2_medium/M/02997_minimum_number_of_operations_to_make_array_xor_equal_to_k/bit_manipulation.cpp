class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int nums_xor {0};

        for (const int& num : nums) {
            nums_xor ^= num;
        }

        return (
            __builtin_popcount(nums_xor - (nums_xor & k)) +
            __builtin_popcount(k - (nums_xor & k))
        );
    }
};
