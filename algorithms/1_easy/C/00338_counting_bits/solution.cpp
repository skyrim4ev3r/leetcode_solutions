class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.reserve(static_cast<size_t>(n + 1));

        for (int i{0}; i <= n; ++i) {
            res.push_back(__builtin_popcount(i));
        }

        return res;
    }
};
