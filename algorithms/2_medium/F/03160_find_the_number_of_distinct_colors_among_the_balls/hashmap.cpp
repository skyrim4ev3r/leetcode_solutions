class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        const size_t len {queries.size()};
        vector<int> res;
        res.reserve(len);
        unordered_map<int, int> freqs_colors {};
        unordered_map<int, int> curr_colors {};

        for (const auto& q : queries) {
            const int x {q[0]};
            const int new_color {q[1]};
            auto it {curr_colors.find(x)};

            if (it != curr_colors.end()) {
                const int old_color {it->second};
                auto it_freq {freqs_colors.find(old_color)};
                it_freq->second -= 1;

                if (it_freq->second == 0) {
                    freqs_colors.erase(it_freq);
                }
            }

            curr_colors[x] = new_color;
            freqs_colors[new_color] += 1;

            res.push_back(static_cast<int>(freqs_colors.size()));
        }

        return res;
    }
};
