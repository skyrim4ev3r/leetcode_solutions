class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const size_t len{cost.size()};

        for (size_t i{len - 3}; i < len; --i) {
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }

        return std::min(cost[0], cost[1]);
    }
};
