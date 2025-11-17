class Solution {
public:
    bool detectCapitalUse(string word) {
        bool is_lower{static_cast<bool>(islower(*word.begin()))};
        bool is_upper{!is_lower};
        bool is_capital{is_upper};

        for (auto it{word.cbegin() + 1}; it != word.cend(); ++it) {
            if (islower(*it)) {
                is_upper = false;
            } else {
                is_capital = false;
                is_lower = false;
            }

            if (!is_capital && !is_lower && !is_upper) {
                return false;
            }
        }

        return true;
    }
};
