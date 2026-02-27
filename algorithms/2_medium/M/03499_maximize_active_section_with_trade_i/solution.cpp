class Solution {
public:
    static int maxActiveSectionsAfterTrade(const string& s) {
        const size_t len{ s.size() };
        int total_ones{ 0 };
        int prev_zeros{ 0 };
        int curr_zeros{ 0 };
        int max{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            switch (s[i]) {
                case '0':
                    curr_zeros += 1;
                    if (prev_zeros > 0) {
                        max = std::max(max, prev_zeros + curr_zeros);
                    }
                    break;
                case '1':
                    if (i > 0 && s[i - 1] == '0') {
                        prev_zeros = curr_zeros;
                        curr_zeros = 0;
                    }
                    total_ones += 1;
                    break;
                default:
                    break;
            }
        }

        return max + total_ones;
    }
};
