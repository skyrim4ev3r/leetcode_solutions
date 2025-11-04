class Solution {
public:
    int minimumChairs(string s) {

        int max{0};
        int balance{0};

        for (const char &ch: s) {
            if (ch == 'E') {
                balance += 1;
                max = std::max(max, balance);
            } else {
                balance -= 1;
            }
        }

        return max;
    }
};
