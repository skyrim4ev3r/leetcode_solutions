typedef ptrdiff_t isize;

class Solution {
    static int lcs(std::span<const char> b1, std::span<const char> b2) {
        if (b1.empty() || b2.empty()) {
            return 0;
        }

        if (b1.size() < b2.size()) {
            std::swap(b1, b2);
        }

        const isize len1 = std::ssize(b1);
        const isize len2 = std::ssize(b2);
        auto dp = vector<int>(2 * (len2 + 1), 0);
        int* curr = &dp[0];
        int* next = &dp[len2 + 1];

        for (isize idx1 = len1 - 1; idx1 >= 0; idx1 -= 1) {
            for (isize idx2 = len2 - 1; idx2 >= 0; idx2 -= 1) {
                if (b1[idx1] == b2[idx2]) {
                    curr[idx2] = 1 + next[idx2 + 1];
                } else {
                    curr[idx2] = std::max(curr[idx2 + 1], next[idx2]);
                }
            }

            int* temp = curr;
            curr = next;
            next = temp;
        }

        return next[0];
    }
public:
    static int minDistance(const string& word1, const string& word2) {
        const auto b1 = std::span<const char>(word1.data(), word1.size());
        const auto b2 = std::span<const char>(word2.data(), word2.size());
        return static_cast<int>(std::ssize(b1) + std::ssize(b2)) - 2 * lcs(b1, b2);
    }
};
