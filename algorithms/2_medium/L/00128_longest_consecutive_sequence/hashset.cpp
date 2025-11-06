class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniques(nums.begin(), nums.end());
        int max{0};

        for (const int &num: uniques) {
            if (uniques.find(num + max) != uniques.end() && uniques.find(num - 1) == uniques.end()) {
                int right{num};

                while (uniques.find(right + 1) != uniques.end()) {
                    right += 1;
                }

                max = std::max(max, right - num + 1);
            }
        }

        return max;
    }
};
