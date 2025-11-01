class Solution {
public:
    vector<string> stringSequence(string target) {

        string screen{""};
        vector<string> res {};

        for (const char &ch: target) {
            screen.push_back(0);

            for (char last_ch{'a'}; last_ch <= ch; ++last_ch) {
                screen.back() = last_ch;
                res.push_back(screen);
            }
        }

        return res;
    }
};
