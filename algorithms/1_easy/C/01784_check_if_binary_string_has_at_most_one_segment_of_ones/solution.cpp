class Solution {
public:
    bool checkOnesSegment(string s) {
        const size_t len{ s.size() };
        int count{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
                count += 1;

                if (count > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};
