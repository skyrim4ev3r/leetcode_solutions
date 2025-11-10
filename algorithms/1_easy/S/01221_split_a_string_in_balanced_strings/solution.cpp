class Solution {
public:
    int balancedStringSplit(string s) {

        int count{0};
        int curr_diff{0};

        for (const char &ch: s) {
            if (ch == 'R') {
                curr_diff += 1;
            } else {
                curr_diff -= 1;
            }

            if (curr_diff == 0) {
                count += 1;
            }
        }

        return count;
    }
};
