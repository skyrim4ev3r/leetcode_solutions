class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<size_t, vector<int>> groups_map{};
        vector<vector<int>> res{};
        const size_t len{groupSizes.size()};

        for (size_t i{0}; i < len; ++i) {
            const size_t g_size{static_cast<size_t>(groupSizes[i])};
            groups_map[g_size].push_back(static_cast<int>(i));

            if (groups_map[g_size].size() == g_size) {
                res.push_back(move(groups_map[g_size]));
            }
        }

        return res;
    }
};
