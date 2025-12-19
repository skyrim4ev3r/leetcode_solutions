class Solution {
    static void dfs(
        size_t ppl,
        unordered_map<size_t, vector<size_t>>& map_now,
        vector<bool>& knows,
        unordered_set<size_t>& is_visited
    ) {
        if (!is_visited.insert(ppl).second) {
            return;
        }

        for (const size_t& other_ppl : map_now[ppl]) {
            knows[other_ppl] = true;
            dfs(other_ppl, map_now, knows, is_visited);
        }
    }

    static inline void check_current_state(
        unordered_map<size_t, vector<size_t>>& map_now,
        vector<bool>& knows
    ) {
        unordered_set<size_t> is_visited;
        is_visited.reserve(map_now.size());

        for (const auto& it : map_now) {
            if (knows[it.first]) {
                dfs(it.first, map_now, knows, is_visited);
            }
        }

        map_now.clear();
    }

public:
    static vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(static_cast<size_t>(n), 0);
        knows[0] = true;
        knows[static_cast<size_t>(firstPerson)] = true;
        unordered_map<size_t, vector<size_t>> map_now;

        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        const size_t len{meetings.size()};

        for (size_t i{0}; i < len; ++i) {
            const size_t ppl1{static_cast<size_t>(meetings[i][0])};
            const size_t ppl2{static_cast<size_t>(meetings[i][1])};

            if (i > 0 && meetings[i][2] != meetings[i - 1][2]) {
                check_current_state(map_now, knows);
            }

            if (knows[ppl1]) {
                knows[ppl2] = true;
            } else if (knows[ppl2]) {
                knows[ppl1] = true;
            } else {
                map_now[ppl1].push_back(ppl2);
                map_now[ppl2].push_back(ppl1);
            }
        }

        check_current_state(map_now, knows);

        vector<int> res;
        for (int i{0}; i < n; ++i) {
            if (knows[static_cast<size_t>(i)]) {
                res.push_back(i);
            }
        }

        return res;
    }
};
