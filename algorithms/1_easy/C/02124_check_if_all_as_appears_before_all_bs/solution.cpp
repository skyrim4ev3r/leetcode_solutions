class Solution {
public:
    bool checkString(string s) {
        for (auto it{s.cbegin() + 1}; it != s.cend(); ++it) {
            if (*it < *(it - 1)) {
                return false;
            }
        }

        return true;
    }
};
