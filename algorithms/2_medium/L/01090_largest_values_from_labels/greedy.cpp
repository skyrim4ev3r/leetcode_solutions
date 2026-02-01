class Solution {
    static inline vector<pair<int, int>> zip(
        const vector<int>& values,
        const vector<int>& labels
    ) {
        const size_t len{ values.size() };
        vector<pair<int, int>> res;
        res.reserve(len);

        for (size_t i{ 0 }; i < len; ++i) {
            res.push_back({values[i], labels[i]});
        }

        return res;
    }

public:
    static int largestValsFromLabels(
        const vector<int>& values,
        const vector<int>& labels,
        const int num_wanted,
        const int use_limit
    ) {
        auto arr{ zip(values, labels) };
        ranges::sort(arr, [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        unordered_map<int, int> freqs;
        int res{ 0 };
        int count{ 0 };

        for (const auto& [val, label] : arr) {
            if (count >= num_wanted) {
                break;
            }

            int& freq{ freqs[label] };

            if (freq < use_limit) {
                freq += 1;
                count += 1;
                res += val;
            }
        }

        return res;
    }
};
