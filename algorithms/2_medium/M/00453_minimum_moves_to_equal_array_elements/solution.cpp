class Solution {
public:
    static int minMoves(const vector<int>& nums) {
        const int min{ *min_element(nums.cbegin(), nums.cend()) };
        int count{ 0 };

        for (const auto& num : nums) {
            count += num - min;
        }

        return count;
    }
};
