class Solution {
public:
    string largestOddNumber(string num) {
        const size_t len{num.size()};
        size_t right_index{len - 1};

        while (right_index < len && ((num[right_index] - '0') & 1) == 0) {
            right_index -= 1;
        }

        if (right_index > len) {
            return "";
        }

        return num.substr(0, right_index + 1);
    }
};
