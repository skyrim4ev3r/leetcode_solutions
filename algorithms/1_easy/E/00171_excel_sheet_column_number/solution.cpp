class Solution {
public:
    static int titleToNumber(const string& col_title) {
        int count = 0;

        for(const auto ch : col_title) {
            count = count * 26 + (ch - ('A' - 1));
        }

        return count;
    }
};
