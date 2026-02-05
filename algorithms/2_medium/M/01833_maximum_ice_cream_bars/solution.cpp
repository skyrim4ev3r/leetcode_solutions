class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ranges::sort(costs);
        int count{ 0 };

        for (const auto& cost : costs) {
            if (cost <= coins) {
                coins -= cost;
                count += 1;
            } else {
                break;
            }
        }

        return count;
    }
};
