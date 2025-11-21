class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) {
            return "0";
        }

        string res{};
        res.reserve(13);
        int dig_count{0};

        while (n > 0) {
            dig_count += 1;
            res.push_back(static_cast<char>(n % 10) + '0');
            n /= 10;

            if (n > 0 && dig_count % 3 == 0) {
                res.push_back('.');
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
