typedef ptrdiff_t isize;

class Solution {
    static int dfs(const string& s, const isize len,const isize lo, const isize hi, vector<int>& memo) {
        if (lo < 0 || hi >= len) {
            return 0;
        }

        const isize memo_idx = lo * len + hi;

        if (memo[memo_idx] != -1) {
            return memo[memo_idx];
        }

        int res = 0;
        if (s[lo] == s[hi]) {
            res = 2 + dfs(s, len, lo - 1, hi + 1, memo);
        } else {
            res = std::max(dfs(s, len, lo, hi + 1, memo), dfs(s, len, lo - 1, hi, memo));
        };

        memo[memo_idx] = res;
        return res;
    }

public:
    int longestPalindromeSubseq(const string& s) {
        const isize len = std::ssize(s);
        auto memo = vector<int>(len * len, -1);
        int max_palindrom = 0;

        for (isize i = 0; i < len; i += 1) {
            max_palindrom = std::max(max_palindrom, 1 + dfs(s, len, i - 1, i + 1, memo));
            max_palindrom = std::max(max_palindrom, dfs(s, len, i, i + 1, memo));
        }

        return max_palindrom;
    }
};
