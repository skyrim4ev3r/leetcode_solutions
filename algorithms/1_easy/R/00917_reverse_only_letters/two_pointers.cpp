class Solution {
    inline bool is_valid_char(const char &c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
public:
    string reverseOnlyLetters(string s) {
        size_t right{s.size() - 1};
        size_t left{0};

        while (left < right) {
            while (left < right && !is_valid_char(s[right]))  {
                right -= 1;
            }

            while (left < right && !is_valid_char(s[left])) {
                left += 1;
            }

            if (left >= right) {
                break;
            }

            const char temp = s[right];
            s[right] = s[left];
            s[left] = temp;

            right -= 1;
            left += 1;
        }

        return s;
    }
};
