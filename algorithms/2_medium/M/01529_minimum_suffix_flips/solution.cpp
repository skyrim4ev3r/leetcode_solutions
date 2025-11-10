class Solution {
public:
    int minFlips(string target) {
        int count{0};
        char prev_ch{'0'};

        for (auto it{target.cbegin()}; it != target.cend(); ++it) {
            if (*it != prev_ch) {
                prev_ch = *it;
                count += 1;
            }
        }

        return count;
    }
};
