class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> nums_set{};
        int max{INT_MIN};

        for (const int &num: nums) {
            if (num > 0) {
                nums_set.insert(num);
            }
            max = std::max(num, max);
        }

        if (nums_set.empty()) {
            return max;
        }

        return accumulate(nums_set.begin(), nums_set.end(), 0);
    }
};
