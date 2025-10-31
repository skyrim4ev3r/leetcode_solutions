class Solution {
    inline bool is_valid(char &ch) {
        return ('A' <= ch && ch <= 'Z') ||
               ('a' <= ch && ch <= 'z') ||
               ('0' <= ch && ch <= '9');
    }
public:
    bool isPalindrome(string s) {
        size_t right{s.size() - 1};
        size_t left{0};

        while (left < right) {
            if (!is_valid(s[left])) {
                left += 1;
            } else if (!is_valid(s[right])) {
                right -= 1;
            } else {
                if (std::tolower(s[left]) != std::tolower(s[right])) {
                    return false;
                }
                right -= 1;
                left += 1;
            }
        }

        return true;
    }
};
