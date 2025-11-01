class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int last_distinct{INT_MIN};
        int count{0};

        for (const int &num: nums) {
            const int max_possible{num + k};

            if (last_distinct < max_possible) {
                last_distinct = max(last_distinct + 1, num - k);
                count += 1;
            }
        }

        return count;
    }
};
