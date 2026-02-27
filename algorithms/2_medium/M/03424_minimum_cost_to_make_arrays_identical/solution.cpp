class Solution {
    static inline long long calc_cost(const vector<int>& arr, const vector<int>& brr) {
        const size_t len{ arr.size() };
        long long cost{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            cost += std::abs(static_cast<long long>(arr[i]) - static_cast<long long>(brr[i]));
        }

        return cost;
    }
public:
    static long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        const long long by_default_cost{ calc_cost(arr, brr) };
        ranges::sort(arr);
        ranges::sort(brr);
        const long long by_sort_cost{ calc_cost(arr, brr) + k };

        return std::min(by_default_cost, by_sort_cost);
    }
};
