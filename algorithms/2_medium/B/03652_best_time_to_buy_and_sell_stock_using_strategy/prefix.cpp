class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        const size_t len{prices.size()};
        vector<long long> prefix(len + 1, 0);
        const size_t k_usize{static_cast<size_t>(k)};

        for (size_t i{0}; i < len; ++i) {
            prefix[i + 1] = prefix[i] + static_cast<long long>(prices[i]) * static_cast<long long>(strategy[i]);
        }

        long long curr{reduce(prices.begin() + (k_usize / 2), prices.begin() + k_usize, 0LL)};
        long long max{prefix[len]};
        max = std::max(max, prefix[len] - prefix[k_usize] + curr);

        for (size_t i{k_usize}; i < len; ++i) {
            curr = curr - static_cast<long long>(prices[i - (k_usize / 2)]) + static_cast<long long>(prices[i]);
            max = std::max(max, prefix[len] - prefix[i + 1] + prefix[i - k_usize + 1] + curr);
        }

        return max;
    }
};
