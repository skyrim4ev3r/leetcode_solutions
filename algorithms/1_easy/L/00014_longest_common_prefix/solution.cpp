class Solution {
    static inline size_t calc_min_str_len(const vector<string>& strs) {
        size_t min_len = numeric_limits<size_t>::max();
        for (const auto& s : strs) {
            min_len = std::min(min_len, s.size());
        }
        return min_len;
    }

    static inline size_t calc_pos(const vector<string>& strs) {
        const size_t input_len = strs.size();
        const size_t min_str_len = calc_min_str_len(strs);
        size_t pos = 0;
        while (pos < min_str_len) {
            for (size_t i = 1; i < input_len; ++i) {
                if (strs[i][pos] != strs[i - 1][pos]) {
                    return pos;
                }
            }

            pos += 1;
        }
        return pos;
    }
public:
    static string longestCommonPrefix(const vector<string>& strs) {
        size_t pos = calc_pos(strs);
        return strs[0].substr(0, pos);
    }
};
