class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res{};
        const size_t len{s.size()};
        size_t left{0};

        for (size_t right{0}; right < len; ++right) {
            if (right == len - 1 || s[right] != s[right + 1]) {
                if (right - left + 1 > 2) {
                    res.push_back(vector<int>{static_cast<int>(left), static_cast<int>(right)});
                }

                left = right + 1;
            }
        }

        return res;
    }
};
