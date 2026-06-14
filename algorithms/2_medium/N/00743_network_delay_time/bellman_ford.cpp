class Solution {
public:
    static int networkDelayTime(const vector<vector<int>>& times, const int n, const int k) {
        assert(times.size() > 0 && n > 0 && k > 0 && k <= n);

        auto dist = vector<int>(static_cast<size_t>(n) + 1, numeric_limits<int>::max());
        dist[k] = 0;

        for (int _steps = 0; _steps < n; _steps += 1) {
            bool is_updated = false;

            for (const auto& t : times) {
                assert(t.size() == 3);
                const int u = t[0];
                const int v = t[1];
                const int w = t[2];
                assert(u > 0 && v > 0 && u <= n && v <= n && w >= 0);

                if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    is_updated = true;
                }
            }

            if (!is_updated) { 
                break;
            }
        }

        const int max_dist = *std::max_element(dist.cbegin() + 1, dist.cend());

        return max_dist == numeric_limits<int>::max() ? -1 : max_dist;
    }
};
