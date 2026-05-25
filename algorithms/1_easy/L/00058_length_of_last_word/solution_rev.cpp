class Solution {
public:
    static int lengthOfLastWord(const string& s) {
        int count = 0;

        for (auto it = s.rbegin(); it != s.rend(); it += 1) {
            if (*it != ' ') {
                count += 1;
            } else if (count != 0) {
                return count;
            }
        }

        return count;
    }
};
