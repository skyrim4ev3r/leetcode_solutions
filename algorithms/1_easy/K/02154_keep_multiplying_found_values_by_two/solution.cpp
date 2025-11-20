class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> exact(nums.begin(), nums.end());

        while (exact.find(original) != exact.end()) {
            original *= 2;
        }

        return original;
    }
};
