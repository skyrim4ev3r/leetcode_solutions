class Solution {
public:
    vector<int> partitionLabels(string s) {
        const size_t len {s.size()};
        array<size_t, 26> last_seen{};
        vector<int> res{};

        for (size_t i{0}; const char& ch : s) {
            last_seen[static_cast<size_t>(ch - 'a')] = i;
            i += 1;
        }

        size_t left {0};
        size_t target_right {0};

        for (size_t right {0}; right < len; ++right) {
            target_right = std::max(
                target_right,
                last_seen[static_cast<size_t>(s[right] - 'a')]
            );

            if (target_right == right) {
                res.push_back(static_cast<int>(right - left) + 1);
                left = right + 1;
            }
        }

        return res;
    }
};
