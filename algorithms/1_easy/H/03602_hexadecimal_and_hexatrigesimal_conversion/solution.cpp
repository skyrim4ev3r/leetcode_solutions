class Solution {
    string to_custom_base(int num, const int base) {
        if (num == 0) {
            return "0";
        }

        string res{};

        while (num > 0) {
            const int remainder{num % base};
            if (remainder < 10) {
                res.push_back(static_cast<char>(remainder + '0'));
            } else {
                res.push_back(static_cast<char>(remainder - 10 + 'A'));
            }

            num /= base;
        }

        reverse(res.begin(), res.end());

        return res;
    }
public:
    string concatHex36(int n) {
        return to_custom_base(n * n, 16) + to_custom_base(n * n * n, 36);
    }
};
