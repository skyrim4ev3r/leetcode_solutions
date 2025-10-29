class Solution {
    bool is_palindrome(string &s, size_t left, size_t right, int penalty) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (penalty > 0) {
                    return is_palindrome(s, left + 1, right, penalty - 1) ||
                           is_palindrome(s, left, right - 1, penalty - 1);
                } else {
                    return false;
                }
            }

            left += 1;
            right -= 1;
        }

        return true;
    }
public:
    bool validPalindrome(string s) {
        return is_palindrome(s, 0, s.size() - 1, 1);
    }
};
