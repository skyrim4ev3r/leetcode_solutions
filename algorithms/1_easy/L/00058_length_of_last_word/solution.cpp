class Solution {
public:
    int lengthOfLastWord(string s) {

        int count{0};
        bool is_counting_started{false};

        for (auto it{s.rbegin()}; it != s.rend(); ++it) {
            if (*it != ' ') {
                is_counting_started = true;
            }

            if (is_counting_started) {
                if (*it != ' ') {
                    count += 1;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
