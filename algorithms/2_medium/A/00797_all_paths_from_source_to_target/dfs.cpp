class Solution {
    void dfs(const vector<vector<int>>& graph, const size_t curr_index, const size_t target_index, vector<int> &curr_vec, vector<vector<int>> &res) {
        curr_vec.push_back(static_cast<int>(curr_index));

        if (curr_index == target_index ){
            res.push_back(curr_vec);
        } else {
            for (auto next_index: graph[curr_index]) {
                dfs(graph, static_cast<size_t>(next_index), target_index, curr_vec, res);
            }
        }

        curr_vec.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res{};
        vector<int> temp;
        temp.reserve(graph.size());
        const size_t target_index{graph.size() - 1};
        const size_t start_index{0};

        dfs(graph, start_index, target_index, temp, res);

        return res;
    }
};
