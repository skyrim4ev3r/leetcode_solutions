class Solution {
    void dfs(
        set<int> &pool,
        vector<bool> &is_visited,
        const size_t pool_id,
        const size_t node_id,
        const vector<vector<int>> &al,
        vector<size_t> &node_id_to_pool_id
    ) {
        if (is_visited[node_id]) {
            return;
        }

        is_visited[node_id] = true;
        node_id_to_pool_id[node_id] = pool_id;
        pool.insert(static_cast<int>(node_id));

        for (const int &other: al[node_id]) {
            dfs(pool, is_visited, pool_id, static_cast<size_t>(other), al, node_id_to_pool_id);
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        const size_t c_usize{static_cast<size_t>(c) + 1};
        vector<vector<int>> al(c_usize, vector<int>());

        for (const auto &connection: connections) {
            al[static_cast<size_t>(connection[0])].push_back(connection[1]);
            al[static_cast<size_t>(connection[1])].push_back(connection[0]);
        }

        vector<bool> is_visited(c_usize, false);
        vector<bool> is_online(c_usize, true);
        vector<size_t> node_id_to_pool_id(c_usize, 0);
        vector<set<int>> pools{};
        vector<int> res;

        for (size_t i{1}; i < c_usize; ++i) {
            if (!is_visited[i]) {
                const size_t pool_id{pools.size()};
                pools.push_back(set<int>{});
                auto &curr_pool = pools.back();
                dfs(curr_pool, is_visited, pool_id, i, al, node_id_to_pool_id);
            }
        }

        for (const auto &query: queries) {
            const size_t curr_node_id{static_cast<size_t>(query[1])};
            const int curr_node{query[1]};

            if (query[0] == 2) {
                is_online[curr_node_id] = false;
                pools[node_id_to_pool_id[curr_node_id]].erase(curr_node);
            } else {
                if (is_online[curr_node_id]) {
                    res.push_back(curr_node);
                } else {
                    const auto &pool = pools[node_id_to_pool_id[curr_node_id]];

                    if (pool.empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(*pool.begin());
                    }
                }
            }
        }

        return res;
    }
};
