class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        const size_t len{cost.size()};

        for (size_t i{1}; i < len; ++i) {
            cost[i] = std::min(cost[i], cost[i - 1]);
        }

        return cost;
    }
};
