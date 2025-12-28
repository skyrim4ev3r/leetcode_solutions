class Solution {
public:
    static long long minCost(const string& s, vector<int>& cost) {
        const size_t len {s.size()};
        array<long long, 26> cost_chars {};
        long long total_cost {0};

        for (size_t i{0}; i < len; ++i) {
            cost_chars[static_cast<size_t>(s[i] - 'a')] += static_cast<long long>(cost[i]);
            total_cost += static_cast<long long>(cost[i]);
        }

        long long max {0};

        for (const auto& cost_char : cost_chars) {
            max = std::max(max, cost_char);
        }

        return total_cost - max;
    }
};
