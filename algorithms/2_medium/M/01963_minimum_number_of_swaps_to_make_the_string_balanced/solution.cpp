class Solution {
public:
    int minSwaps(string s) {
        int curr_balance{0};
        int min_balance{0};

        for (const char& ch : s) {
            if (ch == '[') {
                curr_balance += 1;
            } else {
                curr_balance -= 1;
            }

            min_balance = std::min(min_balance, curr_balance);
        }

        return (std::abs(min_balance) + 1) / 2;
    }
};
