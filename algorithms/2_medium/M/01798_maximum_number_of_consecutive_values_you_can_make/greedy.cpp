class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        ranges::sort(coins);
        int curr{ 0 };

        for (const auto& coin : coins) {
            if (coin <= curr+ 1) {
                curr += coin;
            } else {
                break;
            }
        }

        return curr + 1; // len([0..curr]) is curr + 1
    }
};
