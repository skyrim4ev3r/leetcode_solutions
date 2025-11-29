class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count{0};

        for (const int& num : nums) {
            if (num < k) {
                count += 1;
            }
        }

        return count;
    }
};
