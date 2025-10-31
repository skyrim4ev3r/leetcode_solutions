class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) {
            return "0";
        }

        string res{""};
        bool is_negative{num < 0};
        num = abs(num);

        while (num > 0) {
            res.push_back(static_cast<char>(num % 7) + '0');
            num /= 7;
        }

        if (is_negative) {
            res.push_back('-');
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
