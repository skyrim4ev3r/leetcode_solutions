class Solution {
public:
    static int minimumCost(vector<int>& cost) {
        const size_t len = cost.size();
        int total_cost = 0;

        std::sort(cost.begin(), cost.end(), std::greater<>());

        for (size_t i = 0; i < len; i += 3) {
            total_cost += cost[i] + (i + 1 < len ? cost[i + 1] : 0);
        }

        return total_cost;
    }
};
