class Solution {
public:
    static string multiply(const string& num1, const string& num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        const size_t len1 = num1.size();
        const size_t len2 = num2.size();
        string res;
        res.reserve(std::max(len1, len2) * 2);

        for (size_t i = 0; i < len1; i += 1) {
            char carry = 0;

            for (size_t j = 0; j < len2; j += 1) {
                const size_t pos = i + j;

                if (pos >= res.size()) {
                    res.push_back(0);
                }

                const char curr_val = (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0') + carry + res[pos];
                res[pos] =  curr_val % 10;
                carry = curr_val / 10;
            }

            if (carry > 0) {
                res.push_back(carry);
            }
        }

        res.shrink_to_fit();
        for (char& ch : res) {
            ch += '0';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
