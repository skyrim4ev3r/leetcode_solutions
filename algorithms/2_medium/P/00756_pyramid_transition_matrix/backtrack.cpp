class Solution {
    void backtrack(
        const unordered_map<string, vector<char>> &map,
        const string& prev,
        string& curr,
        bool& state,
        unordered_set<string>& seen
    ) {
        if (state || (prev.size() == 2 && curr.size() == 1)) {
            state = true;
            return;
        }

        if (curr.size() == prev.size() - 1) {
            if (!seen.insert(curr).second) {
                return;
            }

            string temp_new;
            temp_new.reserve(curr.size() - 1);

            backtrack(map, curr, temp_new, state, seen);
        } else {
            const string base {prev.substr(curr.size(), 2)};
            const auto it {map.find(base)};

            if (it != map.end()) {
                for (const char& ch : it->second) {
                    curr.push_back(ch);
                    backtrack(map, prev, curr, state, seen);
                    curr.pop_back();

                    if (state) {
                        return;
                    }
                }
            }
        }
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> map {};
        unordered_set<string> seen {};

        for (const string& a : allowed) {
            map[a.substr(0, 2)].push_back(a[2]);
        }

        string temp;
        temp.reserve(bottom.size() - 1);
        bool state {false};

        backtrack(map, bottom, temp, state, seen);

        return state;
    }
};
