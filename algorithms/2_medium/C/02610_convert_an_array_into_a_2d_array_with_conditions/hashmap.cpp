class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> map{};
        int max_freq{0};

        for (const int &num: nums) {
            map[num] += 1;
        }

        for (const auto &it: map) {
            max_freq = max(max_freq, it.second);
        }

        vector<vector<int>> res(static_cast<size_t>(max_freq), vector<int>{});

        for (const auto &[num, freq]: map) {
            for (int i{0}; i < freq; ++i) {
                res[i].push_back(num);
            }
        }

        return res;
    }
};
