class Solution {
    static int dfs(
        const string& t1,
        const size_t t1_idx,
        const size_t t1_len,
        const string& t2,
        const size_t t2_idx,
        const size_t t2_len,
        vector<int>& memo
    ) {
        if (t1_idx == t1_len || t2_idx == t2_len) {
            return 0;
        }

        const size_t memo_idx = (t1_idx * t2_len) + t2_idx;
        if (memo[memo_idx] != -1) {
            return memo[memo_idx];
        }

        int max = 0;

        if (t1[t1_idx] == t2[t2_idx]) {
            max = 1 + dfs(t1, t1_idx + 1, t1_len, t2, t2_idx + 1, t2_len, memo);
        } else {
            const int skip1 = dfs(t1, t1_idx + 1, t1_len, t2, t2_idx, t2_len, memo);
            const int skip2 = dfs(t1, t1_idx, t1_len, t2, t2_idx + 1, t2_len, memo);
            max = skip1 > skip2 ? skip1 : skip2;
        }

        memo[memo_idx] = max;

        return max;
    }

public:
    static int longestCommonSubsequence(const string& text1, const string& text2) {
        const size_t t1_len = text1.size();
        const size_t t2_len = text2.size();
        const size_t t1_start_idx = 0;
        const size_t t2_start_idx = 0;
        const size_t memo_len = t1_len * t2_len;
        auto memo = vector<int>(memo_len, -1);

        return dfs(text1, t1_start_idx, t1_len, text2, t2_start_idx, t2_len, memo);
    }
};