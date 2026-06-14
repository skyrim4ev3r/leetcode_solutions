class Solution {
public:
    static int networkDelayTime(const vector<vector<int>>& times, const int n, const int k) {
        assert(n > 0 && k > 0 && k <= n);
        auto min_heap = priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>>();
        auto adj = vector<vector<pair<int, int>>>(static_cast<size_t>(n) + 1, vector<pair<int, int>>());
        for (const auto& t : times) {
            assert(t[0] > 0 && t[1] > 0);
            assert(t[0] <= n && t[1] <= n);
            assert(t[2] >= 0);
            adj[t[0]].push_back(make_pair(t[1], t[2]));
        }
        auto costs = vector<int>(static_cast<size_t>(n) +1, numeric_limits<int>::max());
        min_heap.push(make_pair(0, k));
        
        while (!min_heap.empty()) {
            const auto [path_cost, node] = min_heap.top();
            min_heap.pop();
            if (path_cost > costs[node]) {
                continue;
            }
            
            costs[node] = path_cost;
            
            for (const auto [other_node, edge_cost] : adj[node]) {
                const int new_path_cost = edge_cost + path_cost;
                if (new_path_cost < costs[other_node]) {
                    costs[other_node] = new_path_cost;
                    min_heap.push(make_pair(new_path_cost, other_node));
                }
            }
        }
        
        const int max_dist = *std::max_element(costs.cbegin() + 1, costs.cend());
        
        return max_dist == numeric_limits<int>::max() ? -1 : max_dist;
    }
};
