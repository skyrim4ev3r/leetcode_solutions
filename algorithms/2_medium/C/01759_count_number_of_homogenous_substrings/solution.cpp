const int MOD_TO{ 1'000'000'007 };

class Solution {
public:
    int countHomogenous(string s) {
        char prev_char{ ' ' };
        int total_count{ 0 };
        int contiguous_count{ 0 };

        for (const auto& ch : s) {
            if (ch == prev_char) {
                contiguous_count += 1;
            } else {
                contiguous_count = 1;
                prev_char = ch;
            }

            total_count = (total_count + contiguous_count) % MOD_TO;
        }

        return total_count;
    }
};
