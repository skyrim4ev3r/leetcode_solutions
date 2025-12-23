class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy{numeric_limits<int>::max()};
        int profit{0};

        for (const int& price : prices) {
            if (price - fee > buy) {
                profit += price - fee - buy;
                buy = price - fee;
            }

            buy = std::min(buy, price);
        }

        return profit;
    }
};
