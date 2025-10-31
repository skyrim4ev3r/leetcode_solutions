class Solution {
    void dfs(vector<vector<int>> &is_connected, vector<bool> &is_seen, const size_t n, const size_t row) {
        if (is_seen[row]) {
            return;
        }

        is_seen[row] = true;
        for (size_t i{0}; i < n; ++i) {
            if (is_connected[row][i] == 1) {
                dfs(is_connected, is_seen, n, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& is_connected) {
        const size_t n{is_connected.size()};
        vector<bool> is_seen{vector<bool>(n, false)};
        int count{0};

        for (size_t i{0}; i < n; ++i) {
            if (!is_seen[i]) {
                count += 1;
                dfs(is_connected, is_seen, n, i);
            }
        }

        return count;
    }
};
