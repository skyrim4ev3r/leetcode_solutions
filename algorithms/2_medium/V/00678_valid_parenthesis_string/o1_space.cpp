class Solution {
public:
    static bool checkValidString(const string& s) {
        int points{ 0 };
        int balance{ 0 };

        for (const auto& ch : s) {
            if (ch == ')') {
                balance -= 1;

                if (balance < 0) {
                    if (points > 0) {
                        points -= 1;
                        balance += 1;
                    } else {
                        return false;
                    }
                }
            } else if (ch == '(') {
                balance += 1;
            } else {
                points += 1;
            }
        }

        balance = 0;
        points = 0;

        for (auto it{ s.crbegin() }; it != s.crend(); ++it) {
            if (*it == '(') {
                balance -= 1;

                if (balance < 0) {
                    if (points > 0) {
                        points -= 1;
                        balance += 1;
                    } else {
                        return false;
                    }
                }
            } else if (*it == ')') {
                balance += 1;
            } else {
                points += 1;
            }
        }

        return true;
    }
};
