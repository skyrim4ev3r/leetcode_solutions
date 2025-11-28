class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int balance{0};

        for (const char& ch : s) {
            if (ch == 'a') {
                balance += 1;
            } else {
                balance -= 1;
            }
        }

        return abs(balance);
    }
};
