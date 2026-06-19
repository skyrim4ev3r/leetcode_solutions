typedef ptrdiff_t isize;

class Solution {
    int dfs(
        const std::span<const char> b1,
        const isize idx1,
        const std::span<const char> b2,
        const isize idx2, 
        std::span<int> memo
    )  {
        const isize len1 = b1.size();
        const isize len2 = b2.size();
        if (idx2 == len2) { return 1; }
        if (idx1 == len1) { return 0; }

        const isize remain1 = len1 - idx1;
        const isize remain2 = len2 - idx2;
        if (remain1 < remain2) { return 0; }

        const isize memo_idx = idx1 * len2 + idx2;
        if (memo[memo_idx] != -1) { return memo[memo_idx]; }

        int res = 0;
        if (b1[idx1] == b2[idx2]) {
            res += dfs(b1, idx1 + 1, b2, idx2 + 1, memo);
        }

        res += dfs(b1, idx1 + 1, b2, idx2, memo);
        memo[memo_idx] = res;
        return res;
    }

public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) {
            return 0;
        }

        auto buff = vector<int>(s.size() * t.size(), -1);
        auto b1 = std::span<const char>(s.data(), s.size());
        auto b2 = std::span<const char>(t.data(), t.size());
        auto memo = std::span<int>(buff.data(), buff.size());

        return dfs(b1, 0, b2, 0, memo);
    }
};
