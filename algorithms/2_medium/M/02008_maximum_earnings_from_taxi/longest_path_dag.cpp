class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        assert(n > 0 && n < numeric_limits<int>::max());
        auto best_ending_at = vector<int64_t>(static_cast<size_t>(n) + 1, 0);
        auto adj = vector<vector<pair<int, int>>>(static_cast<size_t>(n) + 1, vector<pair<int, int>>());

        for (const auto& r : rides) {
            adj[r[0]].push_back({ r[1], r[2]});
        }

        int64_t global_best_so_far = 0;
        for (int i = 1; i <= n; i += 1) {
            global_best_so_far = std::max(global_best_so_far, best_ending_at[i]);

            for (const auto& [end, tip] : adj[i]) {
                int64_t ride_earnings = (end - i) + tip;
                int64_t new_profit = global_best_so_far + ride_earnings;
                best_ending_at[end] = std::max(best_ending_at[end], new_profit);
            }
        }

        return global_best_so_far;
    }
};
