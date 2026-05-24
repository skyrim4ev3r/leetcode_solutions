constexpr size_t TOTAL_STEPS = 13;

class Solution {
public:
    static string intToRoman(int num) {
        static const char* symbols[TOTAL_STEPS] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        static const int values[TOTAL_STEPS] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res = "";
        res.reserve(20);

        for (size_t i = 0; i < TOTAL_STEPS; i++) {
            while (num >= values[i]) {
                res += symbols[i];
                num -= values[i];
            }
        }

        return res;
    }
};
