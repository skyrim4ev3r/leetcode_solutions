class Solution {
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            return hash1 ^ (hash2 << 1);
        }
    };
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, int> user_to_activity_count{};
        unordered_set<std::pair<int, int>, PairHash> logs_set{};
        vector<int> res(static_cast<size_t>(k), 0);

        for (const auto& log : logs) {
            logs_set.insert({log[0], log[1]});
        }

        for (const auto& log : logs_set) {
            user_to_activity_count[log.first] += 1;
        }

        for (const auto& [_, count] : user_to_activity_count) {
            res[static_cast<size_t>(count - 1)] += 1;
        }

        return res;
    }
};
