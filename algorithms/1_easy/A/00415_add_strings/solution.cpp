class Solution {
public:
    static string addStrings(const string& num1, const string& num2) {
        const size_t len1{num1.size()};
        const size_t len2{num2.size()};
        string res;
        res.reserve(std::max(len1, len2) + 1);
        res.resize(std::max(len1, len2));

        size_t i1{len1 - 1};
        size_t i2{len2 - 1};
        size_t res_index{res.size() - 1};
        char carry{0};
        while (i1 < len1 || i2 < len2) {
            char ch1{0};
            if (i1 < len1) {
                ch1 = num1[i1] - '0';
                i1 -= 1;
            }

            char ch2{0};
            if (i2 < len2) {
                ch2 = num2[i2] - '0';
                i2 -= 1;
            }

            char sum = ch1 + ch2 + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }

            res[res_index] = sum + '0';
            res_index -= 1;
        }

        if (carry > 0) {
            res.resize(res.size() + 1);
            for (size_t j{res.size() - 1}; j > 0; --j) {
                res[j] = res[j - 1];
            }
            res[0] = carry + '0';
        }

        return res;
    }
};
