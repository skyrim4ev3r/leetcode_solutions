typedef ptrdiff_t isize;

class Solution {
public:
    int minimumDeleteSum(const string& s1, const string& s2) {
        auto b1 = std::span<const char>(s1.data(), s1.size());
        auto b2 = std::span<const char>(s2.data(), s2.size());
        if (b1.size() > b2.size()) {
            std::swap(b1, b2);
        }
        const isize len1 = b1.size();
        const isize len2 = b2.size();
        auto dp = vector<int>(static_cast<size_t>(2 * (len2 + 1)));
        int* curr = &dp[0];
        int* next = &dp[len2 + 1];
        next[len2] = 0;

        for (isize i = len2 - 1; i >= 0; i -= 1) {
            next[i] = next[i + 1] + b2[i];
        }

        for (isize i = len1 - 1; i >= 0; i -= 1) {
            curr[len2] = next[len2] + b1[i];

            for (isize j = len2 - 1; j >= 0; j -= 1) {
                if (b1[i] == b2[j]) {
                    curr[j] = next[j + 1];
                } else {
                    curr[j] = std::min(
                        b1[i] + next[j],
                        b2[j] + curr[j + 1]
                    );
                }
            }

            int* temp = curr;
            curr = next;
            next = temp;
        }

        return next[0];
    }
};
