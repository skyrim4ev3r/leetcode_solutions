class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int curr_min_price{INT_MAX};
        int max_profit{0};

        for (int &price: prices) {
            if (curr_min_price < price) {
                max_profit = std::max(max_profit, price - curr_min_price);
            } else {
                curr_min_price = price;
            }
        }

        return max_profit;
    }
};
