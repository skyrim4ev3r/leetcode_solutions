class Solution {
public:
    int minimumCost(const vector<int>& nums) {
        int min1{ numeric_limits<int>::max() };
        int min2{ numeric_limits<int>::max() };

        for (auto it{ nums.cbegin() + 1 }; it != nums.cend(); ++it) {
            const int num{ *it };

            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        return min1 + min2 + nums[0];
    }
};
