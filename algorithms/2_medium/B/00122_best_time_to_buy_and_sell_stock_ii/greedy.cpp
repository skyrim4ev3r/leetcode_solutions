class Solution {
public:
    static int maxProfit(const vector<int>& prices) {
        const size_t len = prices.size();
        int total = 0;

        for (size_t i = 1; i < len; i += 1) {
            total += std::max(0, prices[i] - prices[i - 1]);
        }

        return total;
    }
};
