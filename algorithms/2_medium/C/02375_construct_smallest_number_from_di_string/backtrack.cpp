class Solution {
    static void backtrack(
        span<char> res,
        const string_view pattern,
        const int curr_idx,
        uint32_t seen,
        bool& res_ready
    ) {
        if (curr_idx == std::ssize(res)) {
            res_ready = true;
            return;
        }

        for (int i = 1; i <= 9; i += 1) {
            const uint32_t mask = 1 << i;
            if ((seen & mask) == 0) {
                if (curr_idx > 0 && pattern[curr_idx - 1] == 'I' && (res[curr_idx - 1] - '0') > i) {
                    continue;
                }

                if (curr_idx > 0 && pattern[curr_idx - 1] == 'D' && (res[curr_idx - 1] - '0') < i) {
                    break;
                }
                res[curr_idx] = i + '0';
                backtrack(res, pattern, curr_idx + 1, seen | mask, res_ready);
            }

            if (res_ready) {
                return;
            }
        }
    }
public:
    static string smallestNumber(const string& pattern) {
        assert(pattern.size() <= 8);
        auto res = string(pattern.size() + 1, ' ');
        bool res_ready = false;
        uint32_t seen = 0;
        backtrack(res, pattern, 0, seen, res_ready);
        return res;
    }
};
