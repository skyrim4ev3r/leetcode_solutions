class Solution {
public:
    static int findJudge(int n, vector<vector<int>>& trust) {
        const size_t len{static_cast<size_t>(n + 1)};
        vector<int> count(len, 0);

        for (const auto& t : trust) {
            count[static_cast<size_t>(t[0])] -= 1;
            count[static_cast<size_t>(t[1])] += 1;
        }

        for (size_t i{1}; i < len; ++i) {
            if (count[i] == n - 1) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};
