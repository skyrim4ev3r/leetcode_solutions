class Solution {
    long long dfs(
        vector<vector<int>>& new_edges,
        vector<int>& values,
        vector<bool>& is_seen,
        long long k,
        int curr,
        int& count
    ) {
        long long val = static_cast<long long>(values[static_cast<size_t>(curr)]);
        is_seen[static_cast<size_t>(curr)] = true;

        for (const int& child : new_edges[static_cast<size_t>(curr)]) {
            if (!is_seen[static_cast<size_t>(child)]) {
                val += dfs(new_edges, values, is_seen, k, child, count);
            }
        }

        if (val % k == 0) {
            count += 1;
            return 0;
        }

        return val;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int count{0};
        vector<vector<int>> new_edges(static_cast<size_t>(n), vector<int>{});
        vector<bool> is_seen(static_cast<size_t>(n), false);

        for (const auto& edge : edges) {
            new_edges[static_cast<size_t>(edge[0])].push_back(edge[1]);
            new_edges[static_cast<size_t>(edge[1])].push_back(edge[0]);
        }

        dfs(new_edges, values, is_seen, static_cast<long long>(k), 0, count);


        return count;
    }
};
