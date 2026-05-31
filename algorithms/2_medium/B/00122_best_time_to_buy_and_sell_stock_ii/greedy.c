int maxProfit(int* prices, int pricesSize)
{
    const size_t len = (size_t) pricesSize;
    int total = 0;

    for (size_t i = 1; i < len; i += 1) {
        if (prices[i] > prices[i - 1]) {
            total += prices[i] - prices[i - 1];
        }
    }

    return total;
}
