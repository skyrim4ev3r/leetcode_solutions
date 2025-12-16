class Solution {
public:
    int minAddToMakeValid(string s) {
        int curr_balance{0};
        int min_balance_left{0};
        int min_balance_right{0};

        for (const char& ch : s) {
            if (ch == '(') {
                curr_balance += 1;
            } else {
                curr_balance -= 1;
            }

            min_balance_left = std::min(min_balance_left, curr_balance);
        }

        curr_balance = 0;
        for (auto it{s.rbegin()}; it != s.rend(); ++it) {
            if (*it == ')') {
                curr_balance += 1;
            } else {
                curr_balance -= 1;
            }

            min_balance_right = std::min(min_balance_right, curr_balance);
        }

        return std::abs(min_balance_left) + std::abs(min_balance_right);
    }
};
