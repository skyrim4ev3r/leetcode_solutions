class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy{ 0 }; // x in s1, y in s2
        int yx{ 0 }; // y in s1, x in s2
        const size_t len{ s1.size() };

        for (size_t i{ 0 }; i < len; ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                xy += 1;
            } else if (s1[i] == 'y' && s2[i] == 'x') {
                yx += 1;
            }
        }

        if (((xy + yx) & 1) == 1) {
            return -1;
        }

        return (xy / 2) + (yx / 2) + (xy & 1) + (yx & 1);
    }
};
