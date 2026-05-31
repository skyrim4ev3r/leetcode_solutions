int maxProfit(int* prices, int pricesSize)
{
    const size_t len = (size_t) pricesSize;
    int curr_min_price = INT_MAX;
    int max_profit = 0;

    for (size_t i = 0; i < len; i += 1) {
        const int price = prices[i];

        if (curr_min_price < price) {
            const int new_profit = price - curr_min_price;

            if (max_profit < new_profit) {
                max_profit = new_profit;
            }
        } else {
            curr_min_price = price;
        }
    }

    return max_profit;
}
