class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        const size_t len{s.size()};
        vector<size_t> diff{};
        array<int, 26> freqs{};

        for (size_t i{0}; i < len; ++i) {
            if (s[i] != goal[i]) {
                if (diff.size() == 2) {
                    return false;
                }

                diff.push_back(i);
            }

            freqs[static_cast<size_t>(s[i] - 'a')] += 1;
        }

        if (diff.size() == 2) {
            if (s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]) {
                return true;
            } else {
                return false;
            }
        }

        if (diff.size() == 0) {
            for (const int& freq : freqs) {
                if (freq > 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
