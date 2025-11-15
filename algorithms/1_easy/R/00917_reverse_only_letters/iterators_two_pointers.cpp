class Solution {
    inline bool is_valid_char(const char &c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
public:
    string reverseOnlyLetters(string s) {
        auto it_right{s.end() - 1};
        auto it_left{s.begin()};

        while (it_left < it_right) {
            while (it_left < it_right && !is_valid_char(*it_right))  {
                it_right -= 1;
            }

            while (it_left < it_right && !is_valid_char(*it_left)) {
                it_left += 1;
            }

            if (it_left >= it_right) {
                break;
            }

            const char temp{*it_right};
            *it_right = *it_left;
            *it_left = temp;

            it_right -= 1;
            it_left += 1;
        }

        return s;
    }
};
