class Solution {
    static inline vector<pair<int, int>> create_zip_costs_capacity(
        const vector<int>& costs,
        const vector<int>& capacity,
        const int budget
    ) {
        size_t count{ 0 };

        for (const auto& cost : costs) {
            if (cost < budget) {
                count += 1;
            }
        }

        vector<pair<int, int>> res;
        res.reserve(count);
        const size_t input_len{ costs.size() };

        for (size_t i{ 0 }; i < input_len; ++i) {
            if (costs[i] < budget) {
                res.push_back({costs[i], capacity[i]});
            }
        }

        ranges::sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        return res;
    }

    static inline vector<int> create_prefix_max_capacity(const vector<pair<int, int>>& arr, const size_t len) {
        vector<int> prefix_max_capacity(len, 0);
        prefix_max_capacity[0] = arr[0].second;

        for (size_t i{ 1 }; i < len; ++i) {
            prefix_max_capacity[i] = std::max(prefix_max_capacity[i - 1], arr[i].second);
        }

        return prefix_max_capacity;
    }
public:
    static int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        const auto arr{ create_zip_costs_capacity(costs, capacity, budget) };
        const size_t len{ arr.size() };

        if (len == 0) {
            return 0;
        }

        const auto prefix_max_capacity{ create_prefix_max_capacity(arr, len) };
        int max{ 0 };
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        };

        for (size_t i{ 0 }; i < len; ++i) {
            const int other_cost{ budget - arr[i].first - 1 };
            const auto upper_bound{ std::upper_bound(arr.cbegin(), arr.cbegin() + i, make_pair(other_cost, 0), comp) };

            if (upper_bound > arr.cbegin()) {
                const size_t upper_bound_index{ static_cast<size_t>(upper_bound - 1 - arr.cbegin()) };
                max = std::max(max, prefix_max_capacity[upper_bound_index] + arr[i].second);
            } else {
                max = std::max(max, arr[i].second);
            }
        }

        return max;
    }
};
