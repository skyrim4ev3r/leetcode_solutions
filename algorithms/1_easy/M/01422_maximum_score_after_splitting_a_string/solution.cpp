class Solution {
public:
    int maxScore(string s) {
        const size_t total_ones{static_cast<size_t>(count(s.begin(), s.end(), '1'))};
        const size_t len{s.size()};
        size_t curr_ones{0};
        size_t curr_zeros{0};
        size_t max_score{0};

        for (size_t i{0}; i < len - 1; ++i) {
            if (s[i] == '0') {
                curr_zeros += 1;
            } else {
                curr_ones += 1;
            }

            max_score = std::max(max_score, curr_zeros + total_ones - curr_ones);
        }

        return max_score;
    }
};
