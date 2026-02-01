class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance{ 0 };
        for (auto it{ s.begin() }; it != s.end(); ++it) {
            if (*it == '(') {
                balance += 1;
            } else if (*it == ')') {
                if (balance > 0) {
                    balance -= 1;
                } else {
                    *it = '*';
                }
            }
        }

        balance = 0;
        for (auto it{ s.rbegin() }; it != s.rend(); ++it) {
            if (*it == ')') {
                balance += 1;
            } else if (*it == '(') {
                if (balance > 0) {
                    balance -= 1;
                } else {
                    *it = '*';
                }
            }
        }

       s.erase(std::remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};
