class Solution {
    int backtrack(const uint32_t i, const uint32_t n, const uint32_t seen, std::span<int> memo) {
        if (i > n) {
            return 1;
        }

        if (memo[seen] != -1) {
            return memo[seen];
        } 

        int res = 0;
        for (uint32_t curr = 1; curr <= n; curr += 1) {
            const uint32_t mask = 1u << curr;
            if ((seen & mask) == 0 && (curr % i == 0 || i % curr == 0)) {
                res += backtrack(i + 1, n, seen | mask, memo);
            }
        }

        memo[seen] = res;
        return res;
    }
public:
    int countArrangement(int n_i32) {
        assert(n_i32 >= 1 && n_i32 <= 15);
        const uint32_t n = static_cast<uint32_t>(n_i32);
        auto buff = vector<int>(1u << (n + 1u), -1);
        auto memo = std::span<int>(buff.data(), buff.size());
        const uint32_t seen = 0;
        return backtrack(1, n , seen, memo);
    }
};
