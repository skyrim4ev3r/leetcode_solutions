class Solution {
public:
    int countBinarySubstrings(string s) {
        const size_t len{s.size()};
        int curr_count{ 1 };
        int prev_count{ 0 };
        int res{ 0 };

        for (size_t i{ 1 }; i < len; ++i) {
            if (s[i] != s[i - 1]) {
                res += std::min(curr_count, prev_count);
                prev_count = curr_count;
                curr_count = 1;
            } else {
                curr_count += 1;
            }
        }

        res += std::min(curr_count, prev_count);

        return res;
    }
};
