class Solution {
    inline void add_i16_binary_to_string(string &res, short num) {

        bool is_leading_zero = true;

        for (int i{15}; i >= 0; --i) {

            char ch = ((num >> i) & 1) + '0';

            if (is_leading_zero && ch == '0') {
                continue;
            }

            is_leading_zero = false;

            res.push_back(ch);
        }
    }
public:
    string convertDateToBinary(string date) {

        string res{};
        string part;
        stringstream ss(date);

        while (getline(ss, part, '-')) {

            if (!res.empty()) {
                res.push_back('-');
            }

            int num = std::stoi(part);

            add_i16_binary_to_string(res, static_cast<short>(num));
        }

        return res;
    }
};
