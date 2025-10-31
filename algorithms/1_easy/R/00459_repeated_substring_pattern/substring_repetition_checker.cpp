class Solution {
    inline vector<size_t> generate_divisor_lengths(size_t n) {
        vector<size_t> res;

        size_t square_root = sqrt(n);

        res.push_back(1);

        for (size_t i{2}; i <= square_root; ++i) {
            if (n % i == 0) {
                res.push_back(i);
                size_t other = n / i;

                if (i != other) {
                    res.push_back(other);
                }
            }
        }

        return move(res);
    }
public:
    bool repeatedSubstringPattern(string s) {

        const size_t len{s.size()};

        if (len == 1) {
            return false;
        }

        vector<size_t> divisor_lengths{generate_divisor_lengths(len)};
        size_t left{0};

        for (const size_t &divisor_length: divisor_lengths) {
            bool is_valid{true};
            left = 0;
            for (size_t right{divisor_length}; right < len; ++right) {
                if (s[right] != s[left]) {
                    is_valid = false;
                    break;
                }

                left += 1;
            }

            if (is_valid) {
                return true;
            }
        }

        return false;
    }
};
