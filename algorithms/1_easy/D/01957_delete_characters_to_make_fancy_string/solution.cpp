class Solution {
public:
    string makeFancyString(string s) {

        int repeats{0};
        char prev_char{0};
        string res{};

        for (const char &ch: s) {
            if (ch == prev_char) {
                repeats += 1;
            } else {
                prev_char = ch;
                repeats = 1;
            }

            if (repeats <= 2) {
                res.push_back(ch);
            }
        }

        return res;
    }
};
