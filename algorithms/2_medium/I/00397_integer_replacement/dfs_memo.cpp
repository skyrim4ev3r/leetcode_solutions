class Solution {
    static int dfs(int64_t n, unordered_map<int64_t, int>& memo) {
        if (n == 1) { return 0; }

        auto it = memo.find(n);

        if (it != memo.end()) {
            return it->second;
        }

        if ((n & 1) == 0) {
            const int res = 1 + dfs(n / 2, memo);
            memo[n] = res;
            return res;
        }

        const int res = 1 + std::min(dfs(n + 1, memo), dfs(n - 1, memo));
        memo[n] = res;
        return res;
    }
public:
    int integerReplacement(int n) {
        assert(n > 0);
        auto memo = unordered_map<int64_t, int>();

        return dfs(n, memo);
    }
};
