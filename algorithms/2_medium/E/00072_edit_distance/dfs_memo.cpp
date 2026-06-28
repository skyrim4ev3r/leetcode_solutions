typedef ptrdiff_t isize;

class Solution {
    static int dfs(string_view w1, isize i1 , string_view w2, isize i2, span<int> memo) {
        const isize len1 = std::ssize(w1);
        const isize len2 = std::ssize(w2);
        if (i1 == len1) {
            return static_cast<int>(len2 - i2);
        }

        if (i2 == len2) {
            return static_cast<int>(len1 - i1);
        }

        const isize memo_idx = i1 * len2 + i2;

        if (memo[memo_idx] != -1) {
            return memo[memo_idx];
        }

        int res = numeric_limits<int>::max();

        if (w1[i1] == w2[i2]) {
            res = dfs(w1, i1 + 1, w2, i2 + 1, memo);
        } else {
            res = 1 + dfs(w1, i1 + 1, w2, i2 + 1, memo);
            res = std::min(res, 1 + dfs(w1, i1, w2, i2 + 1, memo));
            res = std::min(res, 1 + dfs(w1, i1 + 1, w2, i2, memo));
        };

        memo[memo_idx] = res;
        return res;
    }

public:
    static int minDistance(const string& word1, const string& word2) {
        auto memo = vector<int>(std::ssize(word1) * std::ssize(word2), -1);

        return dfs(word1, 0, word2, 0, memo);
    }
};
