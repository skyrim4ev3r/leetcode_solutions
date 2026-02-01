class Solution {
public:
    static bool isValid(string s) {
        const size_t len{ s.size() };
        size_t left{ 0 };

        for (size_t right{ 0 }; right < len; ++right) {
            if (s[right] == 'c') {
                if (left >= 2 && s[left - 1] == 'b' && s[left - 2] == 'a') {
                    left -= 2;
                } else {
                    return false;
                }
            } else {
                s[left] = s[right];
                left += 1;
            }
        }

        return left == 0;
    }
};
