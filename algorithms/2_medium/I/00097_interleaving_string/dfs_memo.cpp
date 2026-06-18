typedef ptrdiff_t isize;

class Solution {
    static bool dfs(
        const std::span<const char> b1,
        const isize b1_idx,
        const std::span<const char> b2,
        const isize b2_idx,
        const std::span<const char> b3,
        const isize b3_idx,
        std::span<char> memo
    ) {
        const isize b1_len = std::ssize(b1);
        const isize b2_len = std::ssize(b2);
        const isize b3_len = std::ssize(b3);

        if (b3_idx == b3_len) {
            return true;
        }

        const isize memo_idx = b1_idx * (b2_len + 1) + b2_idx;

        if (memo[memo_idx] == 0) {
            return false;
        }

        if (b1_idx < b1_len && b1[b1_idx] == b3[b3_idx]) {
            if (dfs(b1, b1_idx + 1, b2, b2_idx, b3, b3_idx + 1, memo)) {
                return true;
            }
        }

        if (b2_idx < b2_len && b2[b2_idx] == b3[b3_idx]) {
            if (dfs(b1, b1_idx, b2, b2_idx + 1, b3, b3_idx + 1, memo)) {
                return true;
            }
        }

        memo[memo_idx] = 0;
        return false;
    }
public:
    static bool isInterleave(const string& s1, const string& s2, const string& s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        if (s1.size() == 0 || s2.size() == 0) {
            return s3 == s1 || s3 == s2;
        }

        auto buff = vector<char>((s1.size() + 1) * (s2.size() + 1), 1);
        auto memo = std::span<char>(buff.data(), buff.size());
        const auto b1 = std::span<const char>(s1.data(), s1.size());
        const auto b2 = std::span<const char>(s2.data(), s2.size());
        const auto b3 = std::span<const char>(s3.data(), s3.size());

        return dfs(b1, 0, b2, 0, b3, 0, memo);
    }
};
